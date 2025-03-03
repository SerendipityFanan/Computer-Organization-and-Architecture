#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalOrder(vector<vector<int>>& graph, vector<int>& inDegree) {
    int n = graph.size();
    vector<int> order;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node + 1);   
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        inDegree[b - 1]++;
    }

    vector<int> result = topologicalOrder(graph, inDegree);

    cout << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}