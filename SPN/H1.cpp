#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

// S替换
void Sbox(char A[]) {
    const char* B[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };
    int sboxMap[] = { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 };
    char temp[5] = "";
    memcpy(temp, A, 4);
    temp[4] = '\0';

    for (int i = 0; i < 16; i++) {
        if (strncmp(temp, B[i], 4) == 0) {
            memcpy(A, B[sboxMap[i]], 4);
            A[4] = '\0';
            return;
        }
    }
}

// P置换
void Pbox(char A[]) {
    char P[17];
    memcpy(P, A, 16);
    P[16] = '\0';
    A[0] = P[0];  A[1] = P[4];  A[2] = P[8];  A[3] = P[12];
    A[4] = P[1];  A[5] = P[5];  A[6] = P[9];  A[7] = P[13];
    A[8] = P[2];  A[9] = P[6];  A[10] = P[10];  A[11] = P[14];
    A[12] = P[3];  A[13] = P[7];  A[14] = P[11];  A[15] = P[15];
    A[16] = '\0';
}

// 异或
void XOR(char A[], const char K[]) {
    for (int i = 0; i < 16; i++) {
        A[i] = ((A[i] - '0') ^ (K[i] - '0')) + '0';
    }
    A[16] = '\0';
}

// SPN加密
void SPN(char x[], const char keys[][17], int Nr) {
    char state[17];
    memcpy(state, x, 16);
    state[16] = '\0';

    // 前Nr-1轮加密
    for (int round = 0; round < Nr - 1; round++) {
        // 与密钥异或
        XOR(state, keys[round]);
        // S盒替换
        for (int i = 0; i < 16; i += 4) {
            char temp[5];
            memcpy(temp, &state[i], 4);
            temp[4] = '\0';
            Sbox(temp);
            memcpy(&state[i], temp, 4);
        }
        // 置换
        Pbox(state);
    }

    // 第Nr轮 
    XOR(state, keys[Nr - 1]);

    // 最终的S盒替换
    for (int i = 0; i < 16; i += 4) {
        char temp[5];
        memcpy(temp, &state[i], 4);
        temp[4] = '\0';
        Sbox(temp);
        memcpy(&state[i], temp, 4);
    }
    // 最后与最终轮密钥异或
    XOR(state, keys[Nr]);
    // 输出加密结果
    cout << state << endl;
}

int main() {
    const char key[33] = "00111010100101001101011000111111"; // 固定密钥
    char k[33];
    memcpy(k, key, 32);
    k[32] = '\0';

    // 生成轮密钥 (4轮，每轮16位)
    char keys[5][17];
    for (int i = 0; i < 5; i++) {
        memcpy(keys[i], &k[i * 4], 16);
        keys[i][16] = '\0';
    }

    ifstream inputFile("D:/fan/homework3/test.txt");
    ofstream outputFile("SPNtest.txt");
    string plaintext;

    while (getline(inputFile, plaintext)) {
        plaintext.resize(16, '0');
        char x[17];
        memcpy(x, plaintext.c_str(), 16);
        x[16] = '\0';

        SPN(x, keys, 4);
        outputFile << plaintext << endl << x << endl; // 输出明文和密文
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
