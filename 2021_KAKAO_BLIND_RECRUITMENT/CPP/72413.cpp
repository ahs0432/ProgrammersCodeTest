#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<int, vector<vector<int>>> loc;
map<int, vector<vector<int>>> searchLoc;
map<int, vector<int>> searchMoney;
map<int, vector<bool>> searchOpPass;
vector<int> lowMoney;

void fareSearch(int now, int dest, int opDest, int money, int user, bool opPass, vector<int> passBy) {
    if (now == dest) {
        searchLoc[user].push_back(passBy);
        searchMoney[user].push_back(money);
        searchOpPass[user].push_back(opPass);

        if (lowMoney[user] == -1 || money < lowMoney[user]) {
            lowMoney[user] = money;
        }
        
        return;
    }

    for (int i = 0; i < loc[now][0].size(); i++) {
        bool alreadyCheck = false;
        for (int passed : passBy) {
            if (passed == loc[now][0][i]) {
                alreadyCheck = true;
                break;
            }
        }

        if (alreadyCheck) {
            continue;
        }

        passBy.push_back(loc[now][0][i]);
        if (opDest == loc[now][0][i]) {
            fareSearch(loc[now][0][i], dest, opDest, money+loc[now][1][i], user, true, passBy);
        } else {
            fareSearch(loc[now][0][i], dest, opDest, money+loc[now][1][i], user, opPass, passBy);
        }
        passBy.pop_back();
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    searchLoc[0] = vector<vector<int>>{{}};
    searchLoc[1] = vector<vector<int>>{{}};
    lowMoney.push_back(-1);
    lowMoney.push_back(-1);
    
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

    /*
    for (map<int, vector<vector<int>>>::iterator itr = loc.begin(); itr != loc.end(); ++itr) {
        cout << itr->first << endl;
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[0][i] << " ";
            cout << itr->second[1][i] << " " << endl;
        }
    }
    */

    fareSearch(s, a, b, 0, 0, false, vector<int>{s});
    fareSearch(s, b, a, 0, 1, false, vector<int>{s});
    int answer = lowMoney[0] + lowMoney[1];

    // 서칭된 것을 이용하여 서로 겹치는 것은 없는지 확인
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < searchLoc[i].size(); j++) {
            if (searchOpPass[i][j]) {
                if (searchMoney[i][j] < answer) {
                    answer = searchMoney[i][j];
                }
                continue;
            }
        }
    }

    return answer;
}

int main() {
    cout << solution(6, 4, 6, 2, vector<vector<int>>{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    //cout << solution(7, 3, 4, 1, vector<vector<int>>{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    //cout << solution(6, 4, 5, 6, vector<vector<int>>{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}}) << endl;
    
    return 0;
}