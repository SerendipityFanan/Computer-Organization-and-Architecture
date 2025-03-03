#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void shortestPath(vector<vector<int>>& graph, int start) {
    int N = graph.size();
    vector<int> dist(N, INF);
    dist[start] = 0;

    for (int k = 0; k < N - 1; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (graph[i][j] != INF && dist[i] != INF && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    // 输出最短路径
    for (int i = 0; i < N; ++i) {
        cout  << dist[i] << endl;
    }
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    // 建立邻接矩阵，初始化为INF
    vector<vector<int>> graph(N, vector<int>(N, INF));

    // 读入边权值
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = weight;
    }

    cout << endl;
    shortestPath(graph, S);

    system("pause");
    return 0;
}