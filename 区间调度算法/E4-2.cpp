#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string name;
    int start;
    int end;
};

bool CompareTasks(Task t1, Task t2) {
    return t1.end < t2.end;
}

vector<string> FindMax(vector<Task>& tasks) {
    vector<std::string> subset;
    sort(tasks.begin(), tasks.end(), CompareTasks);

    subset.push_back(tasks[0].name);
    int lastEnd = tasks[0].end;

    for (int i = 1; i < tasks.size(); i++) {
        if (tasks[i].start >= lastEnd) {
            subset.push_back(tasks[i].name);
            lastEnd = tasks[i].end;
        }
    }

    return subset;
}


int main() {
    int N;
    cin >> N;

    vector<Task> tasks(N);

    for (int i = 0; i < N; i++) {
        cin >> tasks[i].name >> tasks[i].start >> tasks[i].end;
    }

    vector<string> maxSubset = FindMax(tasks);

    cout << endl;
    for (const auto& task : maxSubset) {
        cout << task << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}
