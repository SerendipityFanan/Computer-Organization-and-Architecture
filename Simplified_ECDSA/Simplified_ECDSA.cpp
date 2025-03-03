#include<iostream>
using namespace std;

// 椭圆曲线参数与模数
static const int p = 11;  // 椭圆曲线在Z_p上定义
static const int q = 13;  // 基点A的阶
// 曲线：y² = x³ + x + 6 (mod p)
static const int a = 1;
static const int b = 6;

// 扩展欧几里得算法求逆元
int modInverse(int a, int m) {
    int m0 = m;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    int temp;
    while (a > 1) {
        int q = a / m;
        temp = m;
        m = a % m; a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

// 椭圆曲线加法及倍点运算
// 点表示为(x, y), 使用(-1, -1)代表无穷远点O
struct Point {
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) {}
    Point() : x(-1), y(-1) {}
    bool is_infinity() const { return x == -1 && y == -1; }
};

// 判定点是否在曲线上
bool onCurve(const Point& P) {
    if (P.is_infinity()) return true;
    int lhs = (P.y * P.y) % p;
    int rhs = (((P.x * (long long)P.x) % p) * P.x + (P.x) + b) % p;
    return lhs == (rhs % p);
}

// 椭圆曲线加法：P+Q
Point add(const Point& P, const Point& Q) {
    if (P.is_infinity()) return Q;
    if (Q.is_infinity()) return P;
    if (P.x == Q.x && (P.y + Q.y) % p == 0) {
        // P与Q互为负元，则P+Q=O
        return Point();
    }

    int lambda;
    if (P.x == Q.x && P.y == Q.y) {
        // λ = (3x_P² + a)/(2y_P)
        int numerator = (3 * ((long long)P.x * P.x % p) + a) % p;
        int denominator = (2 * P.y) % p;
        int inv = modInverse(denominator, p);
        lambda = (int)((long long)numerator * inv % p);
    }
    else {
        // λ = (y_Q - y_P)/(x_Q - x_P)
        int numerator = (Q.y - P.y) % p; if (numerator < 0) numerator += p;
        int denominator = (Q.x - P.x) % p; if (denominator < 0) denominator += p;
        int inv = modInverse(denominator, p);
        lambda = (int)((long long)numerator * inv % p);
    }

    int x_r = ((long long)lambda * lambda - P.x - Q.x) % p;
    if (x_r < 0) x_r += p;
    int y_r = ((long long)lambda * (P.x - x_r) - P.y) % p;
    if (y_r < 0) y_r += p;

    return Point(x_r, y_r);
}

// 乘法
Point mul(int k, const Point& P) {
    // 使用二进制分解的快速算法
    Point R; 
    Point base = P;
    while (k > 0) {
        if (k & 1) R = add(R, base);
        base = add(base, base);
        k >>= 1;
    }
    return R;
}

// Hash(x)=2^x mod q
int Hash(int x) {
    // 快速幂模
    int base = 2;
    int res = 1;
    int exp = x;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % q;
        base = (base * base) % q;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x0, y0;
    cin >> x0 >> y0;  // 基点A=(x0,y0)

    int m, x_msg, k_rand;
    cin >> m >> x_msg >> k_rand;  // 私钥m，消息x，随机数k

    // 构造点A
    Point A(x0, y0);

    // 计算kA=(u,v)
    Point kA = mul(k_rand, A);
    int u = kA.x;
    int r = u % q;

    // 计算s = k^-1 * (Hash(x) + m*r) mod q
    int H = Hash(x_msg);
    int mr = (m * r) % q;
    int sum = (H + mr) % q;
    int k_inv = modInverse(k_rand, q);
    int s = (k_inv * sum) % q;
    cout << r << s;

    return 0;
}
