#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Job {
    int start, end, profit, index;
};

bool compareJob(const Job& a, const Job& b) {
    return a.end < b.end;
}

int findLatestNonConflict(const vector<Job>& jobs, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (jobs[j].end <= jobs[i].start) {
            return j;
        }
    }
    return -1;
}

void findMaxProfitJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJob);

    int n = jobs.size();
    vector<int> dp(n, 0);
    vector<vector<int>> selectedJobs(n);

    dp[0] = jobs[0].profit;
    selectedJobs[0].push_back(jobs[0].index);

    for (int i = 1; i < n; i++) {
        int inclProfit = jobs[i].profit;
        int l = findLatestNonConflict(jobs, i);

        if (l != -1) {
            inclProfit += dp[l];
        }

        if (inclProfit > dp[i - 1]) {
            dp[i] = inclProfit;
            selectedJobs[i] = (l != -1) ? selectedJobs[l] : vector<int>();
            selectedJobs[i].push_back(jobs[i].index);
        }
        else {
            dp[i] = dp[i - 1];
            selectedJobs[i] = selectedJobs[i - 1];
        }
    }

    // Print the maximum profit
    cout << dp[n - 1] << endl;

    // Print selected jobs
    for (auto jobIndex : selectedJobs[n - 1]) {
        cout << jobIndex << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
        jobs[i].index = i + 1; // Store 1-based index for each job
    }

    cout << endl;
    findMaxProfitJobs(jobs);

    system("pause");
    return 0;
}