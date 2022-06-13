#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<int, vector<vector<int>>> loc;
int lowMoney = -1;

void searchMove(int money, bool user, vector<int> nowLoc, vector<int> destLoc, vector<vector<int>> passBy) {
    if (nowLoc[user] == destLoc[user]) {
        if (nowLoc[!user] == destLoc[!user]) {
            if (lowMoney == -1 || lowMoney > money) {
                lowMoney = money;
            }
            return;
        } else {
            searchMove(money, !user, nowLoc, destLoc, passBy);
        }
    } else {
        int passedCount = 0;
        for (int i = 0; i < loc[nowLoc[user]][0].size(); i++) {
            bool alreadyCheck = false;
            for (int passed : passBy[user]) {
                if (passed == loc[nowLoc[user]][0][i]) {
                    alreadyCheck = true;
                    passedCount+=1;
                    break;
                }
            }

            if (alreadyCheck) {
                continue;
            }

            int tmpNowLoc = nowLoc[user];

            passBy[user].push_back(loc[nowLoc[user]][0][i]);
            nowLoc[user] = loc[nowLoc[user]][0][i];

            if (nowLoc[user] == nowLoc[!user]) {
                searchMove(money, !user, nowLoc, destLoc, passBy);
            } else {
                searchMove(money+loc[tmpNowLoc][1][i], !user, nowLoc, destLoc, passBy);
            }

            passBy[user].pop_back();
            nowLoc[user] = tmpNowLoc;
        }
        
        if (passedCount == loc[nowLoc[user]][0].size()) {
            return;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (vector<int> fare : fares) {
        if (loc[fare[0]].empty()) {
            loc[fare[0]] = vector<vector<int>>{{}, {}};
        }

        loc[fare[0]][0].push_back(fare[1]);
        loc[fare[0]][1].push_back(fare[2]);

        if (loc[fare[1]].empty()) {
            loc[fare[1]] = vector<vector<int>>{{}, {}};
        }

        loc[fare[1]][0].push_back(fare[0]);
        loc[fare[1]][1].push_back(fare[2]);
    }
    
    searchMove(0, 0, vector<int>{s, s}, vector<int>{a, b}, vector<vector<int>>{{s}, {s}});

    return lowMoney;
}

int main() {
    cout << solution(6, 4, 6, 2, vector<vector<int>>{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    //cout << solution(7, 3, 4, 1, vector<vector<int>>{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    //cout << solution(6, 4, 5, 6, vector<vector<int>>{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}}) << endl;
    
    return 0;
}

// 정확성은 있는데, 효율성은 떨어짐