#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor);
        }
    }
}

int main() {
    cout << "请输入节点数、边数、起点以及连接关系：" << endl;
    int N, M, S;
    cin >> N >> M >> S;
    cout << endl;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << endl;
    vector<bool> visited(N + 1, false);
    cout << "BFS: ";
    BFS(graph, visited, S);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    cout << "DFS: ";
    DFS(graph, visited, S);
    cout << endl;

    system("pause");
    return 0;
}