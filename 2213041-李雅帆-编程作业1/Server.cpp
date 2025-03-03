#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

#define PORT 8888            // 服务器端口号
#define BUFFER_SIZE 1024     // 接收数据的缓冲区大小。

SOCKET serverSocket;
vector<SOCKET> clientSockets;
mutex clientMutex;

// 向客户端发送消息
void broadcastMessage(const string& message, SOCKET excludeSocket) {
    lock_guard<mutex> lock(clientMutex);
    for (SOCKET clientSocket : clientSockets) {
        if (clientSocket != excludeSocket) {
            send(clientSocket, message.c_str(), message.size(), 0);
        }
    }
}

// 处理与单个客户端的连接
void handleClient(SOCKET clientSocket, int userID) {
    char buffer[BUFFER_SIZE];

    string userIDMessage = "您是 " + to_string(userID) + " 号用户\n";
    send(clientSocket, userIDMessage.c_str(), userIDMessage.size(), 0);

    string welcomeMessage = "用户 [" + to_string(userID) + "] 已加入聊天\n";
    broadcastMessage(welcomeMessage, clientSocket);
    cout << welcomeMessage;

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            break;
        }

        buffer[bytesReceived] = '\0';
        string fullMessage = "用户 [" + to_string(userID) + "]: " + string(buffer) + "\n";
        broadcastMessage(fullMessage, clientSocket);
        cout << fullMessage;
    }

    closesocket(clientSocket);
    {
        lock_guard<mutex> lock(clientMutex);
        clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    }

    string leaveMessage = "用户 [" + to_string(userID) + "] 已离开聊天\n";
    broadcastMessage(leaveMessage, clientSocket);
    cout << leaveMessage;
}

void listenForExit() {
    string command;
    while (true) {
        getline(cin, command);
        if (command == "EXIT") {
            broadcastMessage("服务器的连接已断开\n", INVALID_SOCKET);
            {
                lock_guard<mutex> lock(clientMutex);
                for (SOCKET clientSocket : clientSockets) {
                    closesocket(clientSocket);  
                }
                clientSockets.clear();  
            }
            closesocket(serverSocket);  
            WSACleanup();  
            exit(0); 
        }
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup 初始化失败" << endl;
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "创建套接字失败：" << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "绑定地址失败：" << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "监听失败：" << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "服务器已启动，等待客户端连接..." << endl;

    thread exitThread(listenForExit);  
    exitThread.detach();

    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "接受连接失败" << WSAGetLastError() << endl;
            continue;
        }

        {
            lock_guard<mutex> lock(clientMutex);
            clientSockets.push_back(clientSocket);
        }

        thread(handleClient, clientSocket, clientSockets.size()).detach();
    }

    // 清理和关闭
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
