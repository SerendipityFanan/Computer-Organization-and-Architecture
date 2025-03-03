#include<iostream>
#include<fstream>
using namespace std;

const int sbox[16] = { 0xE,0x4,0xD,0x1,0x2,0xF,0xB,0x8,0x3,0xA,0x6,0xC,0x5,0x9,0x0,0x7 };
int T = 8000;
int x[17] = { 0 };
int y[17] = { 0 };
int K[17] = { 0 };
int L1[4] = { 0 };
int L2[4] = { 0 };
int Count[17][17] = { 0 };
int X[8000][16] = { 0 };
int Y[8000][16] = { 0 };

int BinToDec(int n[4])
{
    int s = 8 * n[0] + 4 * n[1] + 2 * n[2] + n[3];
    return s;
}

const char* B[] =
{
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};

void DecToBin(int n, int result[4])
{
    const char* binaryString = B[n];
    for (int i = 0; i < 4; i++)
    {
        result[i] = binaryString[i] - '0';
    }
}

void Inverse(int middle[4], int mmiddle[4])
{
    int l = BinToDec(middle);
    int index = -1;
    for (int p = 0; p < 16; p++)
    {
        if (sbox[p] == l)
        {
            index = p;
            break;
        }
    }
    if (index != -1)
    {
        DecToBin(index, mmiddle);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            mmiddle[i] = 0;
        }
    }
}

void read()
{
    ifstream in("D:/fan/homework3/SPNtest.txt");
    if (!in) {
        cerr << "无法打开文件!" << endl;
        return;
    }
    for (int j = 0; j < T; j++)
    {
        char xx[17], yy[17];
        for (int i = 1; i < 17; i++)
        {
            in >> xx[i];
            X[j][i] = xx[i] - '0';
        }
        for (int i = 1; i < 17; i++)
        {
            in >> yy[i];
            Y[j][i] = yy[i] - '0';
        }
    }
    in.close();
}

int v[17] = { 0 };
int u[17] = { 0 };
int vteam2[4] = { 0 };
int vteam4[4] = { 0 };
int uteam2[4] = { 0 };
int uteam4[4] = { 0 };

void SPNLine()
{
    for (int l = 0; l < T; l++)
    {
        for (int i = 1; i <= 16; i++)
        {
            x[i] = X[l][i];
            y[i] = Y[l][i];
        }
        for (int i = 1; i <= 16; i++)
        {
            DecToBin(i - 1, L1);
            for (int j = 1; j <= 16; j++)
            {
                DecToBin(j - 1, L2);
                for (int k = 1; k <= 4; k++)
                {
                    v[4 + k] = L1[k - 1] ^ y[4 + k];
                }
                for (int k = 1; k <= 4; k++)
                {
                    v[12 + k] = L2[k - 1] ^ y[12 + k];
                }
                for (int a = 5; a <= 8; a++)
                {
                    vteam2[a - 5] = v[a];
                }
                for (int b = 13; b <= 16; b++)
                {
                    vteam4[b - 13] = v[b];
                }
                Inverse(vteam2, uteam2);
                Inverse(vteam4, uteam4);
                int z = x[5] ^ x[7] ^ x[8] ^ uteam2[1] ^ uteam2[3] ^ uteam4[1] ^ uteam4[3];
                if (z == 0)
                {
                    Count[i][j] += 1;
                }
            }
        }
    }
    int max = -1;
    for (int i = 1; i <= 16; i++)
    {
        DecToBin(i - 1, L1);
        for (int j = 1; j <= 16; j++)
        {
            DecToBin(j - 1, L2);
            Count[i][j] = abs(Count[i][j] - T / 2);
            if (Count[i][j] > max)
            {
                max = Count[i][j];
                for (int l = 0; l < 4; l++)
                {
                    K[l] = L1[l];
                    K[4 + l] = L2[l];
                }
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << K[i];
    }
    cout << endl;
}

int main()
{
    read();

    for (int run = 1; run <= 10; run++)
    {

        for (int i = 1; i <= 16; i++)
        {
            for (int j = 1; j <= 16; j++)
            {
                Count[i][j] = 0;
            }
        }
        cout << "第 " << run << " 次输出结果: ";
        SPNLine();
    }

    system("pause");
    return 0;
}