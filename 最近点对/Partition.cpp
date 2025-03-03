#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<iomanip>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

float dist(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float bruteForce(const vector<Point>& points, int start, int end) {
    float minDist = FLT_MAX;
    for (int i = start; i <= end; ++i) {
        for (int j = i + 1; j <= end; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

float stripClosest(const vector<Point>& strip, float d) {
    float minDist = d;
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

float closestUtil(const vector<Point>& px, const vector<Point>& py, int start, int end) {
    if (end - start <= 3) {
        return bruteForce(px, start, end);
    }

    int mid = (start + end) / 2;
    Point midPoint = px[mid];

    vector<Point> pyl, pyr;
    for (size_t i = 0; i < py.size(); ++i) {
        if (py[i].x <= midPoint.x) {
            pyl.push_back(py[i]);
        }
        else {
            pyr.push_back(py[i]);
        }
    }

    float dl = closestUtil(px, pyl, start, mid);
    float dr = closestUtil(px, pyr, mid + 1, end);

    float d = min(dl, dr);

    vector<Point> strip;
    for (size_t i = 0; i < py.size(); ++i) {
        if (abs(py[i].x - midPoint.x) < d) {
            strip.push_back(py[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

float closestPair(vector<Point>& points) {
    vector<Point> px = points;
    vector<Point> py = points;

    sort(px.begin(), px.end(), compareX);
    sort(py.begin(), py.end(), compareY);

    return closestUtil(px, py, 0, points.size() - 1);
}

int main() {
    int N;
    cout << "请输入点的数量 N 和每个点的坐标：" << endl;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    float minDist = closestPair(points);

    cout << endl;
    cout << "最短距离及最近点对坐标："<<endl;
    cout<< fixed << setprecision(2)<<minDist << endl;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (dist(points[i], points[j]) == minDist) {
                cout << points[i].x << " " << points[i].y << endl;
                cout << points[j].x << " " << points[j].y << endl;
                return 0;
            }
        }
    }

    system("pause");
    return 0;
}