#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

#define PORT 8888            // �������˿ں�
#define BUFFER_SIZE 1024     // �������ݵĻ�������С��

SOCKET serverSocket;
vector<SOCKET> clientSockets;
mutex clientMutex;

// ��ͻ��˷�����Ϣ
void broadcastMessage(const string& message, SOCKET excludeSocket) {
    lock_guard<mutex> lock(clientMutex);
    for (SOCKET clientSocket : clientSockets) {
        if (clientSocket != excludeSocket) {
            send(clientSocket, message.c_str(), message.size(), 0);
        }
    }
}

// �����뵥���ͻ��˵�����
void handleClient(SOCKET clientSocket, int userID) {
    char buffer[BUFFER_SIZE];

    string userIDMessage = "���� " + to_string(userID) + " ���û�\n";
    send(clientSocket, userIDMessage.c_str(), userIDMessage.size(), 0);

    string welcomeMessage = "�û� [" + to_string(userID) + "] �Ѽ�������\n";
    broadcastMessage(welcomeMessage, clientSocket);
    cout << welcomeMessage;

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            break;
        }

        buffer[bytesReceived] = '\0';
        string fullMessage = "�û� [" + to_string(userID) + "]: " + string(buffer) + "\n";
        broadcastMessage(fullMessage, clientSocket);
        cout << fullMessage;
    }

    closesocket(clientSocket);
    {
        lock_guard<mutex> lock(clientMutex);
        clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    }

    string leaveMessage = "�û� [" + to_string(userID) + "] ���뿪����\n";
    broadcastMessage(leaveMessage, clientSocket);
    cout << leaveMessage;
}

void listenForExit() {
    string command;
    while (true) {
        getline(cin, command);
        if (command == "EXIT") {
            broadcastMessage("�������������ѶϿ�\n", INVALID_SOCKET);
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
        cerr << "WSAStartup ��ʼ��ʧ��" << endl;
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "�����׽���ʧ�ܣ�" << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "�󶨵�ַʧ�ܣ�" << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "����ʧ�ܣ�" << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "���������������ȴ��ͻ�������..." << endl;

    thread exitThread(listenForExit);  
    exitThread.detach();

    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "��������ʧ��" << WSAGetLastError() << endl;
            continue;
        }

        {
            lock_guard<mutex> lock(clientMutex);
            clientSockets.push_back(clientSocket);
        }

        thread(handleClient, clientSocket, clientSockets.size()).detach();
    }

    // ����͹ر�
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
