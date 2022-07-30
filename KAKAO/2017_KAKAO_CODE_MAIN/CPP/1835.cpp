#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<string> users;
vector<string> user_data;

void dfs(vector<bool> visit, int lastIdx, string ss) {
    visit[lastIdx] = true;
    if (ss.size() == visit.size()) {
        user_data.push_back(ss);
        return;
    }
    
    for (int i = 0; i < users.size(); i++) {
        if (visit[i]) {
            continue;
        }
        
        dfs(visit, i, ss + users[i]);
    }
}

int solution(int n, vector<string> data) {
    users = {"A", "C", "F", "J", "M", "N", "R", "T"};
    user_data = {};
    vector<bool> visit(users.size(), false);
    
    for (int i = 0; i < users.size(); i++) {
        dfs(visit, i, users[i]);
    }

    vector<pair<pair<char, char>, pair<char, int>>> compileData;

    for (string s : data) {
        compileData.push_back({{s[0], s[2]}, {s[3], s[4]-47}});
    }

    int answer = 0;

    for (string s : user_data) {
        bool check = true;
        for (pair<pair<char, char>, pair<int, int>> p : compileData) {
            int fir = -1;
            int sec = -1;

            for (int i = 0; i < s.size(); i++) {
                if (fir != -1 && sec != -1) {
                    break;
                }

                if (p.first.first == s[i]) {
                    fir = i;
                } else if (p.first.second == s[i]) {
                    sec = i;
                }
            }

            if (p.second.first == '=') {
                if (abs(fir - sec) == p.second.second) {
                    continue;
                }
            } else if (p.second.first == '>') {
                if (abs(fir - sec) > p.second.second) {
                    continue;
                }
            } else {
                if (abs(fir - sec) < p.second.second) {
                    continue;
                }
            }

            check = false;
            break;
        }
        
        if (check) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    cout << solution(2, {"N~F=0", "R~T>2"}) << endl;
    cout << solution(2, {"M~C<2", "C~M>1"}) << endl;

    return 0;
}