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
            cerr << "���ѳɹ��뿪������~" << endl;
            break;
        }
        buffer[bytesReceived] = '\0';
        cout << buffer; // ������յ�����Ϣ
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup ��ʼ��ʧ��" << endl;
        return 1;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "�����׽���ʧ�ܣ�" << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "����ʧ��: " << WSAGetLastError() << endl;
        cerr << "����������Ƿ������Լ��������ӡ�" << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "���ӷ������ɹ�" << endl;
    cout << "**********************************************" << endl;
    cout << "��ӭ���������ң�" << endl;
    cout << "������EXIT���˳�����Ŷ��" << endl;
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
