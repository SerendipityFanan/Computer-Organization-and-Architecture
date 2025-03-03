#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

#define PORT 8888
#define BUFFER_SIZE 1024

SOCKET clientSocket;

void receiveMessages() {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            cerr << "您已成功离开聊天室~" << endl;
            break;
        }
        buffer[bytesReceived] = '\0';
        cout << buffer; // 输出接收到的消息
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup 初始化失败" << endl;
        return 1;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "创建套接字失败：" << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "连接失败: " << WSAGetLastError() << endl;
        cerr << "请检查服务器是否运行以及网络连接。" << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "连接服务器成功" << endl;
    cout << "**********************************************" << endl;
    cout << "欢迎来到聊天室！" << endl;
    cout << "（输入EXIT可退出聊天哦）" << endl;
    cout << "**********************************************" << endl;

    thread(receiveMessages).detach();

    char message[BUFFER_SIZE];
    while (true) {
        cin.getline(message, BUFFER_SIZE);
        if (strcmp(message, "EXIT") == 0) {
            break; 
        }
        send(clientSocket, message, static_cast<size_t>(strlen(message)), 0);
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
