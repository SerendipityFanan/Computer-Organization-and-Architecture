﻿#include<iostream>
#include <WINSOCK2.h>
#include <WS2tcpip.h>
#include <time.h>
#include <string>
#include<fstream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

const int MAXSIZE = 1024;
unsigned char FIN = 0b100;
unsigned char ACK = 0b10;
unsigned char SYN = 0b1;
unsigned char ACK_SYN = 0b11;
unsigned char ACK_FIN = 0b110;
unsigned char OVER = 0b111;
double MAX_TIME = 0.5 * CLOCKS_PER_SEC;

void printBinary(unsigned int num) {
	// 48位整数，从最高位开始逐位输出
	for (int bit = 47; bit >= 0; --bit) {
		cout << ((num >> bit) & 1);
		if (bit % 4 == 0) {
			printf(" "); 
		}
	}
	cout << endl;
}

u_short cksum(u_short* message, int size) {
	int count = (size + 1) / 2;
	u_long sum = 0;

	unsigned short* buf = (unsigned short*)malloc(size);
	memset(buf, 0, size);
	memcpy(buf, message, size);

	while (count--) {
		sum += *buf++;
		if (sum & 0xffff0000) {
			sum &= 0xffff;
			sum++;
		}
		 
	}
	u_short result = ~(sum & 0xffff);
	return result;
}

#pragma pack(2)
class Header {
	unsigned short datasize = 0;
 	unsigned short sum = 0;
 	unsigned char tag = 0;
 	unsigned char ack = 0;
 public:
	Header() :datasize((u_short)0), sum((u_short)0), tag((u_char)0), ack((u_char)0) {};
 	void set_tag(unsigned char tag) {
		this->tag = tag;
	}
	void clear_sum() {
		sum = 0;
	}
	void set_sum(unsigned short sum) {
		this->sum = sum;
	}
	unsigned char get_tag() {
		return tag;
	}
	unsigned short get_sum() {
		return sum;
	}
	void set_datasize(unsigned short datasize) {
		this->datasize = datasize;
	}
	void set_ack(unsigned char ack) {
 		this->ack = ack;
	}
	int get_datasize() {
		return datasize;
	}
	unsigned char get_ack() {
		return ack;
	}
	void print_header() {
		printf("datasize:%d，ack:%d\n", get_datasize(), get_ack());
	}
};

class Packet {
private:
	Header header;
	char data_content[MAXSIZE];
 public:
	Packet() :header() {
		memset(data_content, 0, MAXSIZE);
	}
	Header get_header() {
		return header;
	}
	void set_datacontent(char* data_content) {
		memcpy(this->data_content, data_content, header.get_datasize());
 	}
	int get_size() {
		return sizeof(header) + get_datasize();
	}
	void set_datasize(int datasize) {
		header.set_datasize(datasize);
	}
	int get_datasize() {
		return header.get_datasize();
	}
	void set_ack(unsigned char ack) {
		header.set_ack(ack);
	}
	u_char get_ack() {
		return header.get_ack();
	}
	void set_tag(unsigned char tag) {
		header.set_tag(tag);
	}
	void clear_sum() {
		header.clear_sum();
	}
	void set_sum(unsigned short sum) {
		header.set_sum(sum);
	}
	unsigned char get_tag() {
		return header.get_tag();
	}
	unsigned short get_sum() {
		return header.get_sum();
	}
	void printpacketmessage() {
		printf("Packet size=%d bytes，tag=%d，seq=%d，sum=%d，datasize=%d\n", get_size(), get_tag(), get_ack(), get_sum(), get_datasize());
	}
};



int connect(SOCKET& client, SOCKADDR_IN& serv_addr, int& servaddr_len) {
	cout << "开始连接" << endl;
	//三次握手建立连接
	Header header;
	//进行第一次握手：发送SYN
	header.set_tag(SYN);
 	header.clear_sum();
 	header.set_sum(cksum((unsigned short*)&header, sizeof(header)));

	char* send_buffer = new char[sizeof(header)];
	memcpy(send_buffer, &header, sizeof(header)); 
	if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len) == -1)
	{
		cout << "[发送失败]" << "SYN" << endl;
		return -1;
	}
	cout << "[发送]" << "SYN" << endl;
	 

	clock_t start = clock();
	 
	u_long mode = 1;
	ioctlsocket(client, FIONBIO, &mode);

	//第二次握手：接收ACK+SYN
	char* recv_buffer = new char[sizeof(header)];
	while (recvfrom(client, recv_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, &servaddr_len) <= 0) {
		if (clock() - start > MAX_TIME) {
			//超时重传，重新进行第一次握手
			header.set_tag(SYN);
			header.clear_sum();
			header.set_sum(cksum((unsigned short*)&header, sizeof(header)));

			memcpy(send_buffer, &header, sizeof(header)); 
			if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len) == -1)
			{
				cout << "[发送失败]" << "SYN" << endl;
				return -1;
			}
			start = clock();
			cout << "[超时]" << "SYN" << endl;
		}
	}

	mode = 0;
	ioctlsocket(client, FIONBIO, &mode);

 	memcpy(&header, recv_buffer, sizeof(header));
	if (header.get_tag() == ACK_SYN && cksum((unsigned short*)&header, sizeof(header)) == 0) {
		cout << "[接收]" << "SYN 、ACK" << endl;

		//如果接收成功，进行第三次握手：发送ACK
		header.set_tag(ACK);
		header.clear_sum();
		header.set_sum(cksum((unsigned short*)&header, sizeof(header)));
		memcpy(send_buffer, &header, sizeof(header));//将header中的内容复制给发送缓存区
		if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len) == -1)
		{
			cout << "[发送失败]" << "ACK" << endl;
			return -1;
		}
		cout << "[发送]" << "ACK" << endl;

		cout << "连接成功" << endl;
	}
	else {
		//收到的数据包有误
		cout << "[数据包损坏]" << "正在重新发送 SYN" << endl << endl;
		return -1;
	}

}

int disconnect(SOCKET& client, SOCKADDR_IN& serv_addr, int servaddr_len) {
	cout << "开始断开连接" << endl;

	Header header;
	char* send_buffer = new char[sizeof(header)];

	//进行第一次挥手：发送FIN
	header.set_tag(FIN);
	header.clear_sum();
	header.set_sum(cksum((u_short*)&header, sizeof(header)));
	memcpy(send_buffer, &header, sizeof(header));
	if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len) == -1)
	{
		cout << "[发送失败]" << "FIN" << endl;
		return -1;
	}
	cout << "[发送]" << "FIN" << endl;

	clock_t start = clock();
	//记录第一次挥手时间

 	u_long mode = 1;
	ioctlsocket(client, FIONBIO, &mode);

	//进行第二次挥手：接受ACK
	char* recv_buffer = new char[sizeof(header)];
	while (recvfrom(client, recv_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, &servaddr_len) <= 0)
	{
		if (clock() - start > MAX_TIME) 
		{
			header.set_tag(FIN);
			header.clear_sum();
			header.set_sum(cksum((u_short*)&header, sizeof(header)));
			memcpy(send_buffer, &header, sizeof(header)); 
			if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len))
			{
				cout << "[发送失败]" << "FIN" << endl;
				return -1;
			}
			start = clock();
			//更新时间
			cout << "[超时]" << "正在重新发送FIN" << endl;
		}
	}

	//进行校验和检验以及ACK
	memcpy(&header, recv_buffer, sizeof(header));
	if (header.get_tag() == ACK && cksum((unsigned short*)&header, sizeof(header) == 0)) {
		cout << "[接收]" << "ACK" << endl;

	}
	else {
		//检验包出错
		cout << "[接收失败]" << "ACK" << endl;
		return -1;
	}

 	mode = 0;
	ioctlsocket(client, FIONBIO, &mode);

	//进行第三次挥手：等待FIN+ACK
	while (recvfrom(client, recv_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, &servaddr_len) != SOCKET_ERROR) {
		//进行校验和检验，且对ACK标志位进行检测
		memcpy(&header, recv_buffer, sizeof(header));
		if (header.get_tag() == ACK_FIN && cksum((unsigned short*)&header, sizeof(header) == 0)) {
			//检测成功
			cout << "[接收]" << "FIN 、 ACK" << endl;

			//第四次挥手：发送ACK
			header.set_tag(ACK);
			header.clear_sum();
			header.set_sum(cksum((u_short*)&header, sizeof(header)));
			memcpy(send_buffer, &header, sizeof(header)); 
			if (sendto(client, send_buffer, sizeof(header), 0, (sockaddr*)&serv_addr, servaddr_len) == -1)
			{
				cout << "[发送失败]" << "ACK" << endl;

				return -1;
			}
			cout << "[发送]" << "ACK" << endl;
			start = clock();
			cout << "准备退出" << endl;
			break;
		}
	}
	cout << "已退出连接" << endl;
	return 1;
}

int send_package(SOCKET& client, SOCKADDR_IN& server_addr, int& serveraddr_len, char* data_content, int datasize, int& seq) {
	Packet* sendpkt = new Packet();
	sendpkt->set_datasize(datasize); 
	sendpkt->clear_sum(); 
	sendpkt->set_ack((unsigned char)seq); 
	 
	sendpkt->set_datacontent(data_content);

 	sendpkt->set_sum(cksum((u_short*)sendpkt, sendpkt->get_size()));

 	cout << "检查数据包内容：" << endl;
	sendpkt->printpacketmessage();

 	if (sendto(client, (char*)sendpkt, sendpkt->get_size(), 0, (SOCKADDR*)&server_addr, serveraddr_len) == -1) {
		cout << "[发送失败]" << "数据包" << endl;
		return -1;
	}
	cout << "成功发送数据包：" << endl;
	sendpkt->printpacketmessage();

	//记录当前时间
	clock_t start = clock();

	Header* header = new Header();
	//等待接收ACK等信息，同时验证seq
	while (true) {
		u_long mode = 1;
		ioctlsocket(client, FIONBIO, &mode);

		//超时检测
		while (recvfrom(client, (char*)header, MAXSIZE, 0, (SOCKADDR*)&server_addr, &serveraddr_len) <= 0) {
 			if (clock() - start > MAX_TIME) {
 				cout << "[超时]" << "正在重新发送数据包" << endl;

				if (sendto(client, (char*)sendpkt, sendpkt->get_size(), 0, (SOCKADDR*)&server_addr, serveraddr_len) == -1) {
					cout << "[失败]" << "数据包" << endl;
					return -1;
				}
				//重置发送时间
				start = clock();
			}
		}
		//接收到数据，进行序列号的检测和ACK的确认
		if (header->get_ack() == (u_char)seq && header->get_tag() == ACK) {
			cout << "对方已接受到数据包并发送确认:" << endl;
			header->print_header();
			break;
		}
		else {
			continue;
		}
	}
 	u_long mode = 0;
	ioctlsocket(client, FIONBIO, &mode);

	return 1;
}
int send(SOCKET& client, SOCKADDR_IN& server_addr, int& serveraddr_len, char* data_content, int datasize) {
	int package_num = datasize / MAXSIZE + (datasize % MAXSIZE == 0 ? 0 : 1);

  	int seqnum = 0;

	cout << "准备发送当前文件" << endl;

	for (int i = 0; i < package_num; i++) {
		//循环发送所有分开后的数据包
		cout << "发送当前文件中的第" << i << "号数据包：" << endl;
		int len = 0; 
		if (i == package_num - 1)
			len = datasize - (package_num - 1) * MAXSIZE;
		else
			len = MAXSIZE;

 		if (send_package(client, server_addr, serveraddr_len, data_content + i * MAXSIZE, len, seqnum) == -1) {
 			cout << "[发送数据包失败]" << endl;
 			i--;
			continue;
		}
 		seqnum = (seqnum + 1) % 256;
		cout << "第" << i << "号数据包发送成功" << endl << endl;
	}

	Header header;
	header.set_tag(OVER);
	header.set_datasize((u_short)0);
	header.set_ack((u_char)0);
	header.clear_sum();
	header.set_sum(cksum((u_short*)&header, sizeof(header)));

 	char* send_buffer = new char[sizeof(header)];
	memcpy(send_buffer, &header, sizeof(header));
	if (sendto(client, send_buffer, sizeof(header), 0, (SOCKADDR*)&server_addr, serveraddr_len) == -1) {
		cout << "[发送失败]" << "OVER" << endl << endl;
		return -1;
	}
	cout << "[发送]" << "OVER" << endl;

 	clock_t start = clock();

	u_long mode = 1;
	ioctlsocket(client, FIONBIO, &mode);

	char* recv_buffer = new char[sizeof(header)];

	while (true)
	{
		while (recvfrom(client, recv_buffer, sizeof(header), 0, (SOCKADDR*)&server_addr, &serveraddr_len) <= 0) {
			if (clock() - start > MAX_TIME) {
				cout << "[超时]" << "重新发送OVER" << endl;
				if (sendto(client, send_buffer, sizeof(header), 0, (SOCKADDR*)&server_addr, serveraddr_len) == -1) {
					cout << "[发送失败]" << "OVER" << endl;
				}
				start = clock();
			}
		}

		mode = 0;
		ioctlsocket(client, FIONBIO, &mode);

		memcpy(&header, recv_buffer, sizeof(header));
		if (header.get_tag() == OVER && cksum((u_short*)&header, sizeof(header)) == 0) {
			cout << "[接收]" << "OVER" << endl;
			cout << "对方已接受到文件" << endl;
			break;
		}
		else
			continue;
	}
	return 1;
}

int main() {
	SOCKADDR_IN server_addr;

	WSADATA wsadata;
	int err = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (err != 0) {
		perror("WSAStartup 初始化失败!");
		exit(1);
	}

	SOCKET server = socket(AF_INET, SOCK_DGRAM, 0);
	// 建立套接字
	if (server == SOCKET_ERROR) {
		perror("创建客户端失败!");
		WSACleanup();
		exit(1);
	}

	if (InetPton(AF_INET, TEXT("127.0.0.1"), &server_addr.sin_addr.s_addr) != 1) {
		perror("地址无效!");
	}
 	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(6666);
 
	int len = sizeof(server_addr);
	if (connect(server, server_addr, len) == -1) {
		perror("连接失败!");
		exit(1);
	}

	string file;
	cout << "请输入要传输的文件名称:" << endl;
	cin >> file;
	ifstream fin(file.c_str(), ifstream::binary);
	int ptr = 0;
	unsigned char temp = fin.get();
	int index = 0;
	char* buffer = new char[1000000000];
	while (fin) {
		buffer[index] = temp;
		temp = fin.get();
		index++;
	}
	fin.close();

	send(server, server_addr, len, (char*)(file.c_str()), file.length());

	clock_t start_data = clock();
	send(server, server_addr, len, buffer, index);
	clock_t end_data = clock();

	cout << "传输时间：" << (end_data - start_data) / CLOCKS_PER_SEC << "秒" << endl;
	cout << "吞吐率：" << ((float)index) / ((end_data - start_data) / CLOCKS_PER_SEC) << "字节/秒" << endl << endl;
	disconnect(server, server_addr, int(sizeof(server_addr)));
}