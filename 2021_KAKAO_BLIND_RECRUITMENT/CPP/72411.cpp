#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    map<string, int> courseMenus;
    map<int, vector<string>> numCourse;
    map<int, int> bestCount;
    string menu = "";

    for (string order : orders) {
        sort(order.begin(), order.end());
        for (int i = 0; i < order.size(); i++) {
            for (int c : course) {
                for (int j = i+1; j < order.size(); j++) {
                    if (c-1 > order.size()-j) {
                        break;
                    }
                    
                    menu = order[i] + order.substr(j, c-1);

                    courseMenus[menu] += 1;

                    if (courseMenus[menu] != 1) {
                        if (bestCount[c] == courseMenus[menu]) {
                            numCourse[c].push_back(menu);
                        } else if (bestCount[c] < courseMenus[menu]) {
                            bestCount[c] = courseMenus[menu];
                            numCourse[c] = vector<string>{menu};
                        }
                    }

                    menu.clear();
                }
            }
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

    /*
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
    */

    return 0;
}