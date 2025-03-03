#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS

#include <winsock2.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

#define PORT 8888
#define IP "127.0.0.1"
#define PACKETSIZE 1500
#define HEADERSIZE 14
#define DATASIZE (PACKETSIZE-HEADERSIZE)
#define FILE_NAME_MAX_LENGTH 64
#define TIMEOUT 100 // 超时时间（单位：ms）
#define TEST_STOPTIME 100 // send window 满后发送区等待的时间（单位：ms）
double random_drop = 0.02; // 丢包率
int delay_time = 50;       // 延时时间（毫秒）

// 一些header中的标志位
#define SEQ_BITS_START 0
#define ACK_BITS_START 4
#define FLAG_BIT_POSITION 8
#define DATA_LENGTH_BITS_START 10
#define CHECKSUM_BITS_START 12

// 慢启动与拥塞避免状态的标志位
#define SS_STATUS 1 // 慢启动
#define CA_STATUS 2 // 拥塞避免
#define QR_STATUS 3 // 快速恢复

WSAData wsd;
SOCKET sendSocket = INVALID_SOCKET;
SOCKADDR_IN recvAddr = { 0 }; // 接收端地址
SOCKADDR_IN sendAddr = { 0 }; // 发送端地址
int len = sizeof(recvAddr);

clock_t s, l; // 用于计算程序总发送速率的计时变量
clock_t start, last; // 用于检测是否超时的变量
int totalLength = 0; // 总发送字节数
double totalTime = 0; // 总发送时间

#define INIT_SW_SIZE 30 // 初始滑动窗口大小，也即初始threshold
double threshold = INIT_SW_SIZE;
double cwnd = 1;
int status = SS_STATUS; // 现在是SS, CA还是QR
int dup_ack_times = 0; // 用于检测三次重复

// 伪首部14 byte，约定：
// 0 1 2 3--32位seq（0--低8位，3--高8位，下同）
// 4 5 6 7--32位ack
// 8--标志位，低三位分别代表ACK SYN FIN，第四位、第五位暂时起测试功能，代表此次发送的是文件名、文件大小
// 9--空着，全0
// 10 11--数据部分长度
// 12 13--校验和
char header[HEADERSIZE] = { 0 };

char dataSegment[DATASIZE] = { 0 }; // 报文数据部分

char sendBuf[PACKETSIZE] = { 0 }; // header + data

u_short checkSum(const char* input, int length) {
    int count = (length + 1) / 2; // 有多少组16 bits
    u_short* buf = new u_short[count]{ 0 };
    for (int i = 0; i < count; i++) {
        buf[i] = (u_char)input[2 * i] + ((2 * i + 1 < length) ? (u_char)input[2 * i + 1] << 8 : 0);
    }

    register u_long sum = 0;
    while (count--) {
        sum += *buf++;
        if (sum & 0xFFFF0000) {
            sum &= 0xFFFF;
            sum++;
        }
    }
    return ~(sum & 0xFFFF);
}

bool handshake() {
    u_short checksum = 0;

    // 发送第一次握手请求报文
    memset(header, 0, HEADERSIZE);
    int seq = rand();
    header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
    header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
    header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
    header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
    header[FLAG_BIT_POSITION] = 0b010;
    checksum = checkSum(header, HEADERSIZE);
    header[CHECKSUM_BITS_START] = (u_char)(checksum & 0xFF);
    header[CHECKSUM_BITS_START + 1] = (u_char)(checksum >> 8);
    sendto(sendSocket, header, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));
    cout << "[发送]" << "SYN" << endl;

    // 接受第二次握手应答报文
    char recvBuf[HEADERSIZE] = { 0 };
    int recvResult = 0;
    while (true) {
        recvResult = recvfrom(sendSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, &len);
        int ack = recvBuf[ACK_BITS_START] + (recvBuf[ACK_BITS_START + 1] << 8)
            + (recvBuf[ACK_BITS_START + 2] << 16) + (recvBuf[ACK_BITS_START + 3] << 24);
        if ((ack == seq + 1) && (recvBuf[FLAG_BIT_POSITION] == 0b110)) {
            cout << "[接收]" << "SYN 、ACK" << endl;
            break;
        }
        else {
            cout << "[接收失败]接收SYN、ACK失败，握手失败！" << endl;
            return false;
        }
    }

    // 发送第三次握手请求报文
    memset(header, 0, HEADERSIZE);
    int ack = (u_char)recvBuf[SEQ_BITS_START] + ((u_char)recvBuf[SEQ_BITS_START + 1] << 8)
        + ((u_char)recvBuf[SEQ_BITS_START + 2] << 16) + ((u_char)recvBuf[SEQ_BITS_START + 3] << 24) + 1;
    header[ACK_BITS_START] = (u_char)(ack & 0xFF);
    header[ACK_BITS_START + 1] = (u_char)(ack >> 8);
    header[ACK_BITS_START + 2] = (u_char)(ack >> 16);
    header[ACK_BITS_START + 3] = (u_char)(ack >> 24);
    header[FLAG_BIT_POSITION] = 0b100;
    checksum = checkSum(header, HEADERSIZE);
    header[CHECKSUM_BITS_START] = (u_char)(checksum & 0xFF);
    header[CHECKSUM_BITS_START + 1] = (u_char)(checksum >> 8);
    sendto(sendSocket, header, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));
    cout << "[发送失败]" << "ACK" << endl;

    cout << "三次握手成功" << endl;
    return true;
}

int hasSent = 0;
int fileSize = 0;
int sendResult = 0;
int sendSize = 0;
int seq = 1, ack = 0;
int base = 1;
int seq_opp = 0, ack_opp = 0;
int dataLength = 0;
u_short checksum = 0;
bool resend = false;
char recvBuf[HEADERSIZE] = { 0 };
int recvResult = 0;
bool finishSend = false;

bool THREAD_END = false;
int THREAD_CREAT_FLAG = 1;
int index = 0;

void timerThread() {
    while (!THREAD_END) {
        last = clock();
        if (last - start >= TIMEOUT) {
            threshold = cwnd / 2;
            cwnd = 1;
            status = SS_STATUS;
            dup_ack_times = 0;
            if (!finishSend)
                cout << "[超时]" << endl;
            cout << "当前threshold = " << threshold << " MSS " << endl;
            cout << "cwnd = " << cwnd << " MSS "<<endl;

            start = clock();
            resend = true;
        }
    }
}

void recvRespondThread() {
    // 接收响应报文的线程
    while (!THREAD_END) {
        recvResult = recvfrom(sendSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, &len);
        if (recvResult == SOCKET_ERROR) {
            cout << "接收错误！休眠2秒..." << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            continue;
        }

        if (recvBuf[FLAG_BIT_POSITION] == 0b001) {
            // 收到对方用于挥手前结束线程的报文
            break;
        }

        seq_opp = (u_char)recvBuf[SEQ_BITS_START] + ((u_char)recvBuf[SEQ_BITS_START + 1] << 8)
            + ((u_char)recvBuf[SEQ_BITS_START + 2] << 16) + ((u_char)recvBuf[SEQ_BITS_START + 3] << 24);
        ack_opp = (u_char)recvBuf[ACK_BITS_START] + ((u_char)recvBuf[ACK_BITS_START + 1] << 8)
            + ((u_char)recvBuf[ACK_BITS_START + 2] << 16) + ((u_char)recvBuf[ACK_BITS_START + 3] << 24);

        if (recvBuf[FLAG_BIT_POSITION] == 0b100 && ack_opp >= base) {
            base = ack_opp + 1;
            resend = false;
            index = 0;

            if (status == SS_STATUS) {
                cwnd++;
                if (cwnd > threshold) {
                    status = CA_STATUS;
                }
            }
            else if (status == CA_STATUS) {
                cwnd += 1 / ((cwnd > 1) ? floor(cwnd) : 1);
            }
            else if (status == QR_STATUS) {
                status = CA_STATUS;
                cwnd = threshold;
            }

            dup_ack_times = 0;
            cout << "收到正确的ack = " << ack_opp << endl;
            cout << "当前threshold = " << threshold << " MSS " << endl;
            cout << "cwnd = " << cwnd << " MSS" << endl<<endl;
           
            start = clock();
        }
        else {
            dup_ack_times++;
            cout << "重复ACK次数 = " << dup_ack_times << endl;

            if (status != QR_STATUS && dup_ack_times == 3) {
                status = QR_STATUS;
                threshold = cwnd / 2;
                cwnd = threshold + 3;

                resend = true;
                cout << "进入快速恢复(QR)状态！" << endl;
            }
            else if (status == QR_STATUS) {
                cwnd++;
            }

            cout << "收到错误的ack = " << ack_opp << endl;
            cout << "当前threshold = " << threshold << " MSS  " << endl;
            cout << "cwnd = " << cwnd << " MSS " << endl<<endl;
        }

        if (base == (fileSize / (PACKETSIZE - HEADERSIZE) + 2)) {
            finishSend = true;
        }

    }
}

void sendfile(const char* filename) {
    ifstream is(filename, ifstream::in | ios::binary);
    is.seekg(0, is.end);
    fileSize = is.tellg();
    is.seekg(0, is.beg);
    char* filebuf;
    filebuf = (char*)calloc(fileSize, sizeof(char));
    is.read(filebuf, fileSize);
    is.close();

    // 发送文件名
    memset(sendBuf, 0, PACKETSIZE);
    header[FLAG_BIT_POSITION] = 0b1000;
    strcat((char*)memcpy(sendBuf, header, HEADERSIZE) + HEADERSIZE, filename);
    sendto(sendSocket, sendBuf, PACKETSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));

    // 发送文件大小
    memset(sendBuf, 0, PACKETSIZE);
    header[FLAG_BIT_POSITION] = 0b10000;
    strcat((char*)memcpy(sendBuf, header, HEADERSIZE) + HEADERSIZE, to_string(fileSize).c_str());
    sendto(sendSocket, sendBuf, PACKETSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));

    hasSent = 0;
    seq = 1, ack = 0;
    base = 1;
    seq_opp = 0, ack_opp = 0;
    resend = false;
    finishSend = false;
    status = SS_STATUS;
    threshold = INIT_SW_SIZE;
    cwnd = 1;
    dup_ack_times = 0;

   random_device rd;
   mt19937 gen(rd());
   uniform_real_distribution<> dis(0, 1);

    // 开始发送文件
    while (true) {
        if (finishSend) {
            cout << "文件发送完成，共发送 " << fileSize << " 字节" << endl;
            totalLength += fileSize;
            break;
        }

        memset(header, 0, HEADERSIZE);
        memset(dataSegment, 0, DATASIZE);
        memset(sendBuf, 0, PACKETSIZE);
        sendSize = min(PACKETSIZE, fileSize - hasSent + HEADERSIZE);

        if (THREAD_CREAT_FLAG == 1) {
            thread recvRespond(recvRespondThread);
            recvRespond.detach();
            thread timer(timerThread);
            timer.detach();
            THREAD_END = false;
            THREAD_CREAT_FLAG = 0;
        }

        if (resend) {
            if (dataLength == PACKETSIZE - HEADERSIZE) {
                hasSent -= dataLength * (seq - base);
            }
            else {
                hasSent -= dataLength;
                hasSent -= (PACKETSIZE - HEADERSIZE) * (seq - base - 1);
            }

            seq = base;
            resend = false;

            continue;
        }

        if (seq < base + cwnd) {
            if (hasSent < fileSize) {
                header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
                header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
                header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
                header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);

                header[FLAG_BIT_POSITION] = 0b100;

                dataLength = sendSize - HEADERSIZE;
                header[DATA_LENGTH_BITS_START] = dataLength & 0xFF;
                header[DATA_LENGTH_BITS_START + 1] = dataLength >> 8;

                memcpy(dataSegment, filebuf + hasSent, sendSize - HEADERSIZE);
                memcpy(sendBuf, header, HEADERSIZE);
                memcpy(sendBuf + HEADERSIZE, dataSegment, sendSize - HEADERSIZE);
                checksum = checkSum(sendBuf, sendSize);
                header[CHECKSUM_BITS_START] = sendBuf[CHECKSUM_BITS_START] = checksum & 0xFF;
                header[CHECKSUM_BITS_START + 1] = sendBuf[CHECKSUM_BITS_START + 1] = checksum >> 8;

                if (dis(gen) > random_drop) {
                    this_thread::sleep_for(chrono::milliseconds(delay_time));
                    sendResult = sendto(sendSocket, sendBuf, sendSize, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));
                }
                if (base == seq) {
                    start = clock();
                }

                hasSent += sendSize - HEADERSIZE;
                seq++;
            }
        }
        else {
             this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        if (hasSent == fileSize) {
            cout << "已发送字节数 = 文件大小，但还未确认是否完成发送..." << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
            index++;
            if (index == 10)
                finishSend = true;
        }

    }
}

void wavehand() {
    int seq = 0, ack = 0;
    u_short checksum = 0;
    // 发送第一次挥手请求报文
    memset(header, 0, HEADERSIZE);
    seq = rand();
    header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
    header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
    header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
    header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
    header[FLAG_BIT_POSITION] = 0b101;
    checksum = checkSum(header, HEADERSIZE);
    header[CHECKSUM_BITS_START] = (u_char)(checksum & 0xFF);
    header[CHECKSUM_BITS_START + 1] = (u_char)(checksum >> 8);
    sendto(sendSocket, header, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));
    cout << "[发送]" << "FIN" << endl;

    // 接收第二次挥手应答报文
    char recvBuf[HEADERSIZE] = { 0 };
    int recvResult = 0;
    while (true) {
        recvResult = recvfrom(sendSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, &len);
        ack = recvBuf[ACK_BITS_START] + (recvBuf[ACK_BITS_START + 1] << 8)
            + (recvBuf[ACK_BITS_START + 2] << 16) + (recvBuf[ACK_BITS_START + 3] << 24);
        if ((ack == seq + 1) && (recvBuf[FLAG_BIT_POSITION] == 0b100)) {
            cout << "[接收]" << "ACK" << endl;
            break;
        }
        else {
            cout << "[接收失败]接收ACK失败，挥手失败！" << endl;
            return;
        }
    }

    // 接收第三次挥手请求报文
    while (true) {
        recvResult = recvfrom(sendSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, &len);
        ack = recvBuf[ACK_BITS_START] + (recvBuf[ACK_BITS_START + 1] << 8)
            + (recvBuf[ACK_BITS_START + 2] << 16) + (recvBuf[ACK_BITS_START + 3] << 24);
        if ((ack == seq + 1) && (recvBuf[FLAG_BIT_POSITION] == 0b101)) {
            cout << "[接收]" << "FIN 、 ACK" << endl;
            break;
        }
        else {
            cout << "[接收失败]接收FIN 、 ACK失败，挥手失败" << endl;
            return;
        }
    }

    // 发送第四次挥手应答报文
    memset(header, 0, HEADERSIZE);
    seq = ack;
    header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
    header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
    header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
    header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
    ack = (u_char)recvBuf[ACK_BITS_START] + ((u_char)recvBuf[ACK_BITS_START + 1] << 8)
        + ((u_char)recvBuf[ACK_BITS_START + 2] << 16) + ((u_char)recvBuf[ACK_BITS_START + 3] << 24) + 1;
    header[ACK_BITS_START] = (u_char)(ack & 0xFF);
    header[ACK_BITS_START + 1] = (u_char)(ack >> 8);
    header[ACK_BITS_START + 2] = (u_char)(ack >> 16);
    header[ACK_BITS_START + 3] = (u_char)(ack >> 24);
    header[FLAG_BIT_POSITION] = 0b100;
    checksum = checkSum(header, HEADERSIZE);
    header[CHECKSUM_BITS_START] = (u_char)(checksum & 0xFF);
    header[CHECKSUM_BITS_START + 1] = (u_char)(checksum >> 8);
    sendto(sendSocket, header, HEADERSIZE, 0, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR));
    cout << "[发送]" << "ACK" << endl;

    cout << "四次挥手成功,断开连接成功" << endl;
    return;
}

int main() {
    if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) {
        cout << "WSAStartup错误：" << WSAGetLastError() << endl;
        exit(1);
    }
    else {
        cout << "启动成功" << endl;
    }

    sendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sendSocket == SOCKET_ERROR) {
        cout << "创建套接字错误：" << WSAGetLastError() << endl;
        closesocket(sendSocket);
        WSACleanup();
        exit(1);
    }
    else {
        cout << "套接字创建成功" << endl;
    }

    recvAddr.sin_family = AF_INET;
    recvAddr.sin_port = htons(PORT);
    recvAddr.sin_addr.s_addr = inet_addr(IP);
    sendAddr.sin_family = AF_INET;
    sendAddr.sin_port = htons(PORT);
    sendAddr.sin_addr.s_addr = inet_addr(IP);

    if (handshake()) {
        string str;
        cout << "请输入文件名: ";
        cin >> str;

        s = clock();
        sendfile(str.c_str());
        l = clock();
        totalTime = (double)(l - s) / CLOCKS_PER_SEC;

     
        cout << "总发送时间: " << totalTime << " 秒" << endl;
        cout << "发送的总字节数: " << totalLength << " 字节" << endl;
        cout << "吞吐率: " << (double)((totalLength * 8 / 1000) / totalTime) << " kbps" << endl << endl;

        wavehand();
    }

    closesocket(sendSocket);
    WSACleanup();
    return 0;
}
