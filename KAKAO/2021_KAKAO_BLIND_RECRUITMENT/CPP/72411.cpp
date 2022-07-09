#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> courseMenus;
map<int, vector<string>> numCourse;
map<int, int> bestCount;

void dfs(int course, int nowNum, string order, string menu) {
    if (course == 0) {
        courseMenus[menu] += 1;
        int c = menu.size();

        if (courseMenus[menu] != 1) {
            if (bestCount[c] == courseMenus[menu]) {
                numCourse[c].push_back(menu);
            } else if (bestCount[c] < courseMenus[menu]) {
                bestCount[c] = courseMenus[menu];
                numCourse[c] = vector<string>{menu};
            }
        }

        return;
    }

    for (int i = nowNum; i < order.size(); i++) {
        dfs(course-1, i+1, order, menu+order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    courseMenus.clear();
    numCourse.clear();
    bestCount.clear();
    string menu = "";

    for (string order : orders) {
        sort(order.begin(), order.end());
        for (int c : course) {
            dfs(c, 0, order, "");
        }
    }

    vector<string> confirmCourse;

    for (auto iter = numCourse.begin(); iter != numCourse.end(); iter++) {
        for (string data : numCourse[iter->first]) {
            confirmCourse.push_back(data);
        }
    }

    sort(confirmCourse.begin(), confirmCourse.end());

    return confirmCourse;
}

int main() {
    vector<string> aAnswer = solution(vector<string>{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, vector<int>{2,3,4});
    for (string a : aAnswer) {
        cout << a << " ";
    }
    cout << endl;

    vector<string> bAnswer = solution(vector<string>{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, vector<int>{2,3,5});
    for (string b : bAnswer) {
        cout << b << " ";
    }
    cout << endl;

    vector<string> cAnswer = solution(vector<string>{"XYZ", "XWY", "WXA"}, vector<int>{2,3,4});
    for (string c : cAnswer) {
        cout << c << " ";
    }
    cout << endl;

    vector<string> dAnswer = solution(vector<string>{"ABCD", "ABCDE", "AB", "AC", "AF", "AFCE", "ABCDE"}, vector<int>{2,3,4,5});
    for (string d : dAnswer) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}