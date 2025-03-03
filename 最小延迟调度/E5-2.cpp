#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// ��������ṹ��
struct Task {
    int processing_time;
    int deadline;
};

// �ȽϺ���������ֹʱ��������������
bool compareTasks(const Task& a, const Task& b) {
    return a.deadline < b.deadline;
}

vector<pair<int, int>> Min(vector<Task>& tasks) {
    // ����ֹʱ��������������
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
    cout << "�������������������������䴦��ʱ��ͽ�ֹʱ�䣺"<<endl;
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