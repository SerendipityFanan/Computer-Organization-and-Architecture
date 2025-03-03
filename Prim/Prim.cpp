#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int from, to, weight;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1); 
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w)); 
    }

    vector<Edge> mst; 

    visited[1] = true;
    for (int i = 1; i < N; ++i) {
        int minWeight = INT_MAX;
        Edge minEdge;

        for (int u = 1; u <= N; ++u) {
            if (visited[u]) {
                for (auto& edge : graph[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (!visited[v] && weight < minWeight) {
                        minWeight = weight;
                        minEdge = { u, v, weight };
                    }
                }
            }
        }

        visited[minEdge.to] = true;
        mst.push_back(minEdge);
    }

    int totalWeight = 0;

    for (const auto& edge : mst) {
        totalWeight += edge.weight;
    }
    cout << endl;
    cout << totalWeight << endl;

    for (const auto& edge : mst) {
        cout << edge.from << " " << edge.to << " " << edge.weight << endl;
    }

    system("pause");
    return 0;
}