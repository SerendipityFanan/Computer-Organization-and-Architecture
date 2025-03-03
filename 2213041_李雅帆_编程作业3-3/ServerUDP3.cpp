#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>

using namespace std;
#pragma comment(lib, "ws2_32.lib")


#define PORT 8888
#define IP "127.0.0.1"
#define PACKETSIZE 1500
#define HEADERSIZE 14
#define DATASIZE (PACKETSIZE-HEADERSIZE)
#define FILE_NAME_MAX_LENGTH 64
double random_drop = 0.02; // 丢包率 
int delay_time = 110;       // 延时时间（毫秒）
double delay_rate = 0.0;  // 发生延时的概率 


#define SEQ_BITS_START 0
#define ACK_BITS_START 4
#define FLAG_BIT_POSITION 8
#define DATA_LENGTH_BITS_START 10
#define CHECKSUM_BITS_START 12

WSAData wsd;
SOCKET recvSocket = INVALID_SOCKET;
SOCKADDR_IN recvAddr = { 0 };
SOCKADDR_IN sendAddr = { 0 };
int len = sizeof(sendAddr);
char header[HEADERSIZE] = { 0 };

u_short checkSum(const char* input, int length) {
	int count = (length + 1) / 2;
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
	char recvBuf[HEADERSIZE] = { 0 };
	int recvResult = 0;
	int seq, ack;

	// 接收第一次握手请求报文
	while (true) {
		recvResult = recvfrom(recvSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, &len);
		checksum = checkSum(recvBuf, HEADERSIZE);
		seq = (u_char)recvBuf[SEQ_BITS_START] + ((u_char)recvBuf[SEQ_BITS_START + 1] << 8)
			+ ((u_char)recvBuf[SEQ_BITS_START + 2] << 16) + ((u_char)recvBuf[SEQ_BITS_START + 3] << 24);

		if (checksum == 0 && recvBuf[FLAG_BIT_POSITION] == 0b010) {
			cout << "[接收]" << "SYN" << endl;
			break;
		}
		else {
			cout << "[接收失败]接收SYN失败，握手失败！" << endl;
			return false;
		}
	}

	// 发送第二次握手应答报文
	memset(header, 0, HEADERSIZE);
	ack = seq + 1;
	header[ACK_BITS_START] = (u_char)(ack & 0xFF);
	header[ACK_BITS_START + 1] = (u_char)(ack >> 8);
	header[ACK_BITS_START + 2] = (u_char)(ack >> 16);
	header[ACK_BITS_START + 3] = (u_char)(ack >> 24);
	seq = rand() % 65535;
	header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
	header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
	header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
	header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
	header[FLAG_BIT_POSITION] = 0b110;
	sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));
	cout << "[发送]" << "SYN 、ACK" << endl;

	// 接收第三次握手请求报文
	while (true) {
		recvResult = recvfrom(recvSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, &len);
		checksum = checkSum(recvBuf, HEADERSIZE);
		ack = (u_char)recvBuf[ACK_BITS_START] + ((u_char)recvBuf[ACK_BITS_START + 1] << 8)
			+ ((u_char)recvBuf[ACK_BITS_START + 2] << 16) + ((u_char)recvBuf[ACK_BITS_START + 3] << 24);

		if (checksum == 0 && ack == seq + 1 && recvBuf[FLAG_BIT_POSITION] == 0b100) {
			cout << "[接收]" << "ACK" << endl;
			break;
		}
		else {
			cout << "[接收失败]接收ACK失败，握手失败！" << endl;
			return false;
		}
	}
	cout << "三次握手成功" << endl;
	return true;
}

void wavehand() {
	u_short checksum = 0;
	char recvBuf[HEADERSIZE] = { 0 };
	int recvResult = 0;
	int seq, ack;
	// 在recvfile()中已收到第一次挥手请求报文

	// 给recvRespondThread发送结束包
	header[FLAG_BIT_POSITION] = 0b001;
	sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));

	// 发送第二次挥手应答报文
	ack = (u_char)header[SEQ_BITS_START] + ((u_char)header[SEQ_BITS_START + 1] << 8)
		+ ((u_char)header[SEQ_BITS_START + 2] << 16) + ((u_char)header[SEQ_BITS_START + 3] << 24) + 1;
	header[ACK_BITS_START] = (u_char)(ack & 0xFF);
	header[ACK_BITS_START + 1] = (u_char)(ack >> 8);
	header[ACK_BITS_START + 2] = (u_char)(ack >> 16);
	header[ACK_BITS_START + 3] = (u_char)(ack >> 24);
	seq = rand();
	header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
	header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
	header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
	header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
	header[FLAG_BIT_POSITION] = 0b100;
	sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));
	cout << "[发送]" << "ACK" << endl;

	// 发送第三次挥手请求报文
	seq = rand();
	header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
	header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
	header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
	header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
	// ack不变
	header[FLAG_BIT_POSITION] = 0b101;
	sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));
	cout << "[发送]" << "FIN 、 ACK" << endl;

	// 接收第四次挥手应答报文
	while (true) {
		recvResult = recvfrom(recvSocket, recvBuf, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, &len);
		checksum = checkSum(recvBuf, HEADERSIZE);
		ack = (u_char)recvBuf[ACK_BITS_START] + ((u_char)recvBuf[ACK_BITS_START + 1] << 8)
			+ ((u_char)recvBuf[ACK_BITS_START + 2] << 16) + ((u_char)recvBuf[ACK_BITS_START + 3] << 24);
		if (checksum == 0 && recvBuf[FLAG_BIT_POSITION] == 0b100) {
			cout << "[接收]" << "ACK" << endl;
			break;
		}
		else {
			cout << "[接收失败]接收ACK失败，挥手失败！" << endl;
			return;
		}
	}

	cout << "四次挥手成功,已断开连接" << endl;
	return;
}

void recvfile() {
	char recvBuf[PACKETSIZE] = { 0 };
	char dataSegment[DATASIZE] = { 0 };
	char filename[FILE_NAME_MAX_LENGTH] = { 0 };
	int filesize = 0;
	int recvResult = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);

	while (true) {
		// 接收文件名
		recvResult = recvfrom(recvSocket, recvBuf, PACKETSIZE, 0, (SOCKADDR*)&sendAddr, &len);

		if (recvBuf[FLAG_BIT_POSITION] == 0b101) {
			// 记录第一次挥手请求报文的seq
			for (int i = 0; i < 4; i++) {
				header[SEQ_BITS_START + i] = recvBuf[SEQ_BITS_START + i];
			}
			cout << "[接收]" << "FIN" << endl;
			wavehand();
			return;
		}

		if (recvBuf[FLAG_BIT_POSITION] != 0b1000) {
			// 可能是路上的无用报文，忽略
			continue;
		}

		memcpy(header, recvBuf, HEADERSIZE);

		if (header[FLAG_BIT_POSITION] == 0b1000) {
			memcpy(filename, recvBuf + HEADERSIZE, FILE_NAME_MAX_LENGTH);
		}

		// 接收文件大小
		recvResult = recvfrom(recvSocket, recvBuf, PACKETSIZE, 0, (SOCKADDR*)&sendAddr, &len);
		memcpy(header, recvBuf, HEADERSIZE);
		if (header[FLAG_BIT_POSITION] == 0b10000) {
			filesize = atoi(recvBuf + HEADERSIZE);
		}
		cout << "开始接收文件，文件名：" << filename << "，文件大小：" << filesize << " 字节。" << endl;

		int hasReceived = 0;
		int seq_opp = 0, ack_opp = 0;
		int seq = 0, ack = 0;
		int expectedSeq = ack + 1;
		int dataLength = 0;
		u_short checksum = 0;

		ofstream out;
		out.open(filename, ios::out | ios::binary | ios::app);
		while (true) {
			expectedSeq = ack + 1;

			memset(recvBuf, 0, PACKETSIZE);
			recvResult = recvfrom(recvSocket, recvBuf, PACKETSIZE, 0, (SOCKADDR*)&sendAddr, &len);
			if (recvResult == SOCKET_ERROR) {
				cout << "接收错误！休眠2秒..." << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				continue;
			}

			checksum = checkSum(recvBuf, recvResult);
			if (checksum == 0 && recvBuf[FLAG_BIT_POSITION] == 0b100) {
				seq_opp = (u_char)recvBuf[SEQ_BITS_START] + ((u_char)recvBuf[SEQ_BITS_START + 1] << 8)
					+ ((u_char)recvBuf[SEQ_BITS_START + 2] << 16) + ((u_char)recvBuf[SEQ_BITS_START + 3] << 24);
				ack_opp = (u_char)recvBuf[ACK_BITS_START] + ((u_char)recvBuf[ACK_BITS_START + 1] << 8)
					+ ((u_char)recvBuf[ACK_BITS_START + 2] << 16) + ((u_char)recvBuf[ACK_BITS_START + 3] << 24);

				if (seq_opp == expectedSeq) {
					dataLength = recvResult - HEADERSIZE;
					memcpy(dataSegment, recvBuf + HEADERSIZE, dataLength);
					out.write(dataSegment, dataLength);

					seq = seq_opp;
					header[SEQ_BITS_START] = (u_char)(seq & 0xFF);
					header[SEQ_BITS_START + 1] = (u_char)(seq >> 8);
					header[SEQ_BITS_START + 2] = (u_char)(seq >> 16);
					header[SEQ_BITS_START + 3] = (u_char)(seq >> 24);
					ack = seq_opp;
					header[ACK_BITS_START] = (u_char)(ack & 0xFF);
					header[ACK_BITS_START + 1] = (u_char)(ack >> 8);
					header[ACK_BITS_START + 2] = (u_char)(ack >> 16);
					header[ACK_BITS_START + 3] = (u_char)(ack >> 24);
					header[FLAG_BIT_POSITION] = 0b100;

					hasReceived += recvResult - HEADERSIZE;
					cout << "[接收] 数据包序号: " << seq_opp << endl << "数据大小: " << recvResult - HEADERSIZE<< "字节"<< endl;
					cout << "已接收 " << hasReceived << " 字节" << endl;
					cout<<"ack = " << ack << endl<<endl;

					if (dis(gen) < delay_rate)
						this_thread::sleep_for(chrono::milliseconds(delay_time));

					if (dis(gen) > delay_rate)
						sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));
				}
				else {
					if (dis(gen) < delay_rate)
						std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));

					if (dis(gen) > random_drop)
						sendto(recvSocket, header, HEADERSIZE, 0, (SOCKADDR*)&sendAddr, sizeof(SOCKADDR));

					cout << "未收到期望的packet" << endl;
					cout<<"期望seq = " << expectedSeq << "，收到seq = " << seq_opp << endl;
				}
			}
			else {
				cout << "校验和错误或ACK标志错误" << endl;
				continue;
			}

			if (hasReceived == filesize) {
				cout << "成功接收文件 " << filename << "，共接收 " << hasReceived << " 字节。" << endl;
				out.close();

				cout << "文件接收完成，程序即将退出" << endl;
				break; // 退出接收循环
			}

		}
	}
}

int main() {
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) {
		cout << "WSAStartup错误  " << WSAGetLastError() << endl;
		exit(1);
	}
	else {
		cout << "启动成功" << endl;
	}

	recvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (recvSocket == SOCKET_ERROR) {
		cout << "创建套接字错误 = " << WSAGetLastError() << endl;
		closesocket(recvSocket);
		WSACleanup();
		exit(1);
	}
	else {
		cout << "套接字创建成功" << endl;
	}

	recvAddr.sin_family = AF_INET;
	recvAddr.sin_addr.S_un.S_addr = inet_addr(IP);
	recvAddr.sin_port = htons(PORT);
	sendAddr.sin_family = AF_INET;
	sendAddr.sin_port = htons(PORT);
	sendAddr.sin_addr.s_addr = inet_addr(IP);

	if (bind(recvSocket, (SOCKADDR*)&recvAddr, sizeof(recvAddr)) == SOCKET_ERROR) {
		cout << "绑定错误" << WSAGetLastError() << endl;
		closesocket(recvSocket);
		WSACleanup();
		exit(1);
	}
	else {
		cout << "绑定成功" << endl;
	}

	if (handshake()) {
		thread recvfile_thread(recvfile);
		recvfile_thread.join();
	}

	closesocket(recvSocket);
	WSACleanup();
	return 0;
}
