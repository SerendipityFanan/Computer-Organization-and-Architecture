#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����γ̽ṹ��
struct Course {
    string name;
    int start_time;
    int end_time;
};

// �ȽϺ��������ڰ���ʼʱ��Կγ̽�������
bool compareCourses(const Course& a, const Course& b) {
    return a.start_time < b.start_time;
}

int Min(vector<Course>& courses) {
    // ����ʼʱ��Կγ̽�������
    sort(courses.begin(), courses.end(), compareCourses);

    // ����һ�����ҵĽ���ʱ������
    vector<int> end_times;

    for (const auto& course : courses) {
        bool isScheduled = false;
        for (int i = 0; i < end_times.size(); ++i) {
            if (course.start_time >= end_times[i]) {
                // ����ǰ�γ̰��ŵ����н�����
                end_times[i] = course.end_time;
                isScheduled = true;
                break;
            }
        }
        if (!isScheduled) {
            // ��Ҫ�����µĽ���
            end_times.push_back(course.end_time);
        }
    }

    // ���������������
    return end_times.size();
}

int main() {
    int N;
    cout << "������γ�����N���γ��������Ӧ��ʼ����ʱ�䣺" << endl;
    cin >> N;


    vector<Course> courses;

    for (int i = 0; i < N; ++i) {
        string name;
        int start, end;
        cin >> name >> start >> end;
        courses.push_back({ name, start, end });
    }

    int result = Min(courses);
    cout << endl<<result << endl;

    system("pause");
    return 0;
}