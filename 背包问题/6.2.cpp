#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int V, vector<int>& weight, vector<int>& value) {
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][V];
}

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> weight(N), value(N);
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    int result = knapsack(N, V, weight, value);
    cout << endl<<result << endl;

    system("pause");
    return 0;
}