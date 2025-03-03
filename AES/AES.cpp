#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

// S盒
const uint8_t sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

uint8_t substitute(uint8_t byte) {
    return sbox[byte];
}

void rotate(uint8_t* word) {
    uint8_t temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}


// 密钥扩展函数，生成轮密钥
void keyExpansion(const uint8_t* key, uint8_t roundKeys[176]) {
    const uint8_t Rcon[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36 };
    for (int i = 0; i < 16; i++) {
        roundKeys[i] = key[i];
    }
    int currentByte = 16;
    int rconIndex = 0;

    while (currentByte < 176) {
        uint8_t t0 = roundKeys[currentByte - 4];
        uint8_t t1 = roundKeys[currentByte - 3];
        uint8_t t2 = roundKeys[currentByte - 2];
        uint8_t t3 = roundKeys[currentByte - 1];

        if (currentByte % 16 == 0) {
            uint8_t temp = t0;
            t0 = t1;
            t1 = t2;
            t2 = t3;
            t3 = temp;
            t0 = substitute(t0);
            t1 = substitute(t1);
            t2 = substitute(t2);
            t3 = substitute(t3);
            t0 ^= Rcon[rconIndex];
            rconIndex++;
        }
        roundKeys[currentByte] = roundKeys[currentByte - 16] ^ t0;
        roundKeys[currentByte + 1] = roundKeys[currentByte - 15] ^ t1;
        roundKeys[currentByte + 2] = roundKeys[currentByte - 14] ^ t2;
        roundKeys[currentByte + 3] = roundKeys[currentByte - 13] ^ t3;
        currentByte += 4;
    }
}

// 轮密钥加操作，将当前状态与轮密钥异或
void addRoundKey(uint8_t state[16], const uint8_t* roundKey) {
    for (int i = 0; i < 16; i++) {
        uint8_t temp = state[i];   
        temp ^= roundKey[i];      
        state[i] = temp;          
    }
}


// 字节替换操作，对状态中的每个字节进行 S 盒替换
void subBytes(uint8_t state[16]) {
    for (int i = 0; i < 16; i++) {
        state[i] = substitute(state[i]);
    }
}

// 行移位操作，对状态矩阵中的行进行循环移位
void shiftRows(uint8_t state[16]) {
    uint8_t temp = state[1];
    state[1] = state[5];
    state[5] = state[9];
    state[9] = state[13];
    state[13] = temp;

    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    temp = state[3];
    state[3] = state[15];
    state[15] = state[11];
    state[11] = state[7];
    state[7] = temp;
}

// 列混淆操作，对状态矩阵的每列进行混淆运算
void mixColumns(uint8_t state[16]) {
    for (int i = 0; i < 4; i++) {
        uint8_t a = state[i * 4];
        uint8_t b = state[i * 4 + 1];
        uint8_t c = state[i * 4 + 2];
        uint8_t d = state[i * 4 + 3];

        uint8_t temp1 = (a << 1);
        if (a & 0x80) temp1 ^= 0x1B;   
        uint8_t temp2 = (b << 1);
        if (b & 0x80) temp2 ^= 0x1B;   
        state[i * 4] = temp1 ^ temp2 ^ b ^ c ^ d;

        temp1 = (b << 1);
        if (b & 0x80) temp1 ^= 0x1B;   
        temp2 = (c << 1);
        if (c & 0x80) temp2 ^= 0x1B;  
        state[i * 4 + 1] = a ^ temp1 ^ temp2 ^ c ^ d;

        temp1 = (c << 1);
        if (c & 0x80) temp1 ^= 0x1B;   
        temp2 = (d << 1);
        if (d & 0x80) temp2 ^= 0x1B;  
        state[i * 4 + 2] = a ^ b ^ temp1 ^ temp2 ^ d;

        temp1 = (a << 1);
        if (a & 0x80) temp1 ^= 0x1B;   
        temp2 = (d << 1);
        if (d & 0x80) temp2 ^= 0x1B;  
        state[i * 4 + 3] = temp1 ^ a ^ b ^ c ^ temp2;
    }
}

// AES 
void AES(uint8_t* plaintext, const uint8_t* key) {
    uint8_t state[16];
    uint8_t roundKeys[176];
    for (int i = 0; i < 16; i++) state[i] = plaintext[i];
    keyExpansion(key, roundKeys);  // 生成所有轮密钥
    addRoundKey(state, roundKeys);  // 初始轮密钥加

    // 前9轮
    for (int round = 1; round < 10; round++) {
        subBytes(state);       // 字节替换
        shiftRows(state);       // 行移位
        mixColumns(state);      // 列混淆
        addRoundKey(state, roundKeys + round * 16);  // 轮密钥加
    }

    // 最后一轮
    subBytes(state);
    shiftRows(state);
    addRoundKey(state, roundKeys + 160);

    // 输出加密后的密文
    for (int i = 0; i < 16; i++) plaintext[i] = state[i];
}

int main() {
    uint8_t key[16];
    uint8_t plaintext[16];
    string keyInput;
    cin >> keyInput;

    // 转换密钥字符串为字节数组
    for (size_t i = 0; i < 16; i++) {
        string byteString = keyInput.substr(i * 2, 2);
        key[i] = (uint8_t)strtol(byteString.c_str(), nullptr, 16);
    }

    string plaintextInput;
    cin >> plaintextInput;

    // 转换明文字符串为字节数组
    for (size_t i = 0; i < 16; i++) {
        string byteString = plaintextInput.substr(i * 2, 2);
        plaintext[i] = (uint8_t)strtol(byteString.c_str(), nullptr, 16);
    }

    // 执行 AES 加密过程
    AES(plaintext, key);

    // 输出加密后的密文
    for (int i = 0; i < 16; i++) {
        cout << uppercase << hex << setw(2) << setfill('0') << (int)plaintext[i];
    }
    cout << endl;
    return 0;
}

/*
输入示例: (Key & Plaintext 小写 16 进制)
000102030405060708090a0b0c0d0e0f (Key)
00112233445566778899aabbccddeeff (Plaintext)

输出示例: （Ciphertext 大写 16 进制）
69C4E0D86A7B0430D8CDB78070B4C55A (Ciphertext)
*/