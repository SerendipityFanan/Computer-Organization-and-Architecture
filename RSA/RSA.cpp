#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;
typedef __int128 BigInt;

// (base^exp) % mod
BigInt mod_exp(BigInt base, BigInt exp, BigInt mod) {
    BigInt result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return result;
}

// 求 gcd 和模逆
BigInt Extended(BigInt a, BigInt b, BigInt& x, BigInt& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    BigInt x1, y1;
    BigInt gcd = Extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// 模逆运算
BigInt Inverse(BigInt e, BigInt phi) {
    BigInt x, y;
    BigInt g = Extended(e, phi, x, y);
    if (g != 1) {
        throw runtime_error("模逆不存在");
    }
    return (x % phi + phi) % phi;
}

// 128 位整数输入函数
void readBigInt(BigInt& x) {
    string s;
    cin >> s;
    x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0'); 
    }
}

// 128 位整数输出函数
void printBigInt(BigInt x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    string s;
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    BigInt p, q, e, c;
    readBigInt(p);
    readBigInt(q);
    readBigInt(e);
    readBigInt(c);

    BigInt n = p * q;
    BigInt phi = (p - 1) * (q - 1);
    BigInt d = Inverse(e, phi);
    BigInt m = mod_exp(c, d, n);
    printBigInt(m);
    cout << endl;

    return 0;
}
