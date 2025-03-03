#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 定义任务结构体
struct Task {
    int processing_time;
    int deadline;
};

// 比较函数，按截止时间对任务进行排序
bool compareTasks(const Task& a, const Task& b) {
    return a.deadline < b.deadline;
}

vector<pair<int, int>> Min(vector<Task>& tasks) {
    // 按截止时间对任务进行排序
    sort(tasks.begin(), tasks.end(), compareTasks);

    vector<pair<int, int>> time_slots;

    int time = 0;
    for (const auto& task : tasks) {
        time_slots.push_back(make_pair(time, time + task.processing_time));
        time += task.processing_time;
    }

    return time_slots;
}

int main() {
    int N;
    cout << "请输入任务数量、各个任务及其处理时间和截止时间："<<endl;
    cin >> N;

    vector<Task> tasks;

    for (int i = 0; i < N; ++i) {
        int processing_time, deadline;
        cin >> processing_time >> deadline;
        tasks.push_back({ processing_time, deadline });
    }

    cout << endl;
    vector<pair<int, int>> result = Min(tasks);
    for (const auto& slot : result) {
        cout << slot.first << " " << slot.second << endl;
    }

    system("pause");
    return 0;
}