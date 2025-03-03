#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        adjList.resize(n + 1);   
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  
    }

    void BFS(int s) {
        vector<int> dist(adjList.size(), -1);
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<vector<int>> layers(dist.size());
        for (int i = 1; i < dist.size(); i++) {
            layers[dist[i]].push_back(i);
        }

        for (int i = 1; i < layers.size(); i++) {
            if (!layers[i].empty()) {
                for (int node : layers[i]) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    cout << "请输入节点数、边数、BFS的起点以及连接关系：" <<endl;
    int N, M, S;
    cin >> N >> M >> S;
    cout << endl;
    Graph g(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cout << endl;
    cout << "BFS:" << endl;
    cout << S << endl;
    g.BFS(S);

    system("pause");
    return 0;
}