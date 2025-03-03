#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义课程结构体
struct Course {
    string name;
    int start_time;
    int end_time;
};

// 比较函数，用于按开始时间对课程进行排序
bool compareCourses(const Course& a, const Course& b) {
    return a.start_time < b.start_time;
}

int Min(vector<Course>& courses) {
    // 按开始时间对课程进行排序
    sort(courses.begin(), courses.end(), compareCourses);

    // 创建一个教室的结束时间数组
    vector<int> end_times;

    for (const auto& course : courses) {
        bool isScheduled = false;
        for (int i = 0; i < end_times.size(); ++i) {
            if (course.start_time >= end_times[i]) {
                // 将当前课程安排到已有教室中
                end_times[i] = course.end_time;
                isScheduled = true;
                break;
            }
        }
        if (!isScheduled) {
            // 需要开设新的教室
            end_times.push_back(course.end_time);
        }
    }

    // 返回所需教室数量
    return end_times.size();
}

int main() {
    int N;
    cout << "请输入课程数量N、课程名及其对应开始结束时间：" << endl;
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