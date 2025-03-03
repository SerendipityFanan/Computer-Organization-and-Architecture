#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN=1000;

struct Edge {
    int v, cap, rev;
    Edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};

vector<Edge> graph[MAXN]; // 图的邻接表表示
bool visited[MAXN]; // 记录DFS是否访问过某节点
int parent[MAXN]; // 记录DFS过程中每个节点的父节点索引

// 添加有向边
void addEdge(int u, int v, int cap) {
    graph[u].push_back(Edge(v, cap, graph[v].size()));
    graph[v].push_back(Edge(u, 0, graph[u].size() - 1));
}

// 使用DFS寻找增广路径
int dfs(int s, int t, int flow) {
    if (s==t) return flow;
    visited[s]=true;
    for (auto& e : graph[s]) {
        if (!visited[e.v] && e.cap > 0) {
            parent[e.v]=s;
            int augmented_flow=dfs(e.v, t, min(flow, e.cap));
            if (augmented_flow > 0) {
                e.cap-=augmented_flow;
                graph[e.v][e.rev].cap+=augmented_flow;
                return augmented_flow;
            }
        }
    }
    return 0;
}

// 使用Ford-Fulkerson算法求解最大流问题
int fordFulkerson(int s, int t) {
    int maxFlow=0;
    while (true) {
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        int augmented_flow=dfs(s, t, INT_MAX);
        if (augmented_flow==0) break;
        maxFlow+=augmented_flow;
    }
    return maxFlow;
}

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    for (int i=0; i < M; ++i) {
        int u, v, cap;
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }

    int maxFlow=fordFulkerson(S, T);
    cout << endl << maxFlow << endl;

    system("pause");
    return 0;
}