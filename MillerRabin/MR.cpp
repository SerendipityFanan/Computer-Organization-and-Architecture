#include <iostream>
using namespace std;

 long long mul_mod(long long a, long long b, long long m) {
    __int128 res = 0;
    __int128 A = a, B = b, M = m;
    A %= M;
    B %= M;
    while (B > 0) {
        if (B & 1) {
            res = (res + A) % M;
        }
        A = (A + A) % M;
        B >>= 1;
    }
    return (long long)res;
}

// 幂模运算 
long long mod_exp(long long base, long long exp, long long m) {
    long long result = 1 % m;
    long long cur = base % m;
    while (exp > 0) {
        if (exp & 1) {
            result = mul_mod(result, cur, m);
        }
        cur = mul_mod(cur, cur, m);
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin单次测试
bool MR(long long d, long long n, long long a) {
    long long x = mod_exp(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = mul_mod(x, x, n);
        d <<= 1;
        if (x == n - 1)
            return true;
        if (x == 1) 
            return false;
    }
    return false;
}

bool IsPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2; 
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
    }

    long long Test[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (auto a : Test) {
        if (a % n == 0) 
            return true;  
        if (!MR(d, n, a)) 
            return false;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    if (IsPrime(n)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
