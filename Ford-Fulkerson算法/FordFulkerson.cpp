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

vector<Edge> graph[MAXN]; // ͼ���ڽӱ��ʾ
bool visited[MAXN]; // ��¼DFS�Ƿ���ʹ�ĳ�ڵ�
int parent[MAXN]; // ��¼DFS������ÿ���ڵ�ĸ��ڵ�����

// ��������
void addEdge(int u, int v, int cap) {
    graph[u].push_back(Edge(v, cap, graph[v].size()));
    graph[v].push_back(Edge(u, 0, graph[u].size() - 1));
}

// ʹ��DFSѰ������·��
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

// ʹ��Ford-Fulkerson�㷨������������
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