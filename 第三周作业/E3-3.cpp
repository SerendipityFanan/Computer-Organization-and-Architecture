#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int N) {
    vector<int> color(N, -1);
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    cout << "请输入节点数、边数和连接关系：" << endl;
    int N, M;
    cin >> N >> M;

    cout << endl;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    cout << endl;
    if (isBipartite(graph, N)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    system("pause");
    return 0;
}