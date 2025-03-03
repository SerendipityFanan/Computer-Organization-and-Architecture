#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else {
            parent[v] = u;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
};

int kruskal(int N, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
        });

    DisjointSet ds(N);
    int totalWeight = 0;
    vector<Edge> minSpanningTree;

    for (const Edge& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.merge(edge.u, edge.v);
            totalWeight += edge.weight;
            minSpanningTree.push_back(edge);
        }
    }

    cout << totalWeight << endl;
    for (const Edge& edge : minSpanningTree) {
        cout << edge.u + 1 << " " << edge.v + 1 << " " << edge.weight << endl;
    }

    return totalWeight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }
    cout << endl;
    kruskal(N, edges);

    system("pause");
    return 0;
}