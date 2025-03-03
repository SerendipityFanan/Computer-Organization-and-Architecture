#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

void Dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance, vector<vector<int>>& path) {
    int n = graph.size();
    distance.resize(n, INT_MAX);
    path.resize(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    distance[start] = 0;
    path[start].push_back(start);

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) {
            continue;
        }

        for (const Edge& edge : graph[node]) {
            int next = edge.to;
            int next_dist = dist + edge.weight;
            if (next_dist < distance[next]) {
                distance[next] = next_dist;
                path[next] = path[node];
                path[next].push_back(next);
                pq.push({ next_dist, next });
            }
        }
    }
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(to, weight));
    }

    vector<int> distance;
    vector<vector<int>> path;
    Dijkstra(graph, S, distance, path);
    cout << endl;

    for (int i = 0; i < N; ++i) {
        if (distance[i] == INT_MAX) {
            cout << S << "->" << i << ":-1" << endl;
        }
        else {
            cout << S << "->" << i << ":" << distance[i] << "----[";
            for (int j = 0; j < path[i].size(); ++j) {
                cout << path[i][j] << " ";
            }
             cout<< "]" << endl;
        }
    }

    system("pause");
    return 0;
}