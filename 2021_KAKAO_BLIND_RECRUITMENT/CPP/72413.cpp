#include <string>
#include <vector>
#include <iostream>
#include <map>

#define INF 2147483647

using namespace std;

map<int, vector<vector<int>>> loc;
map<int, int> money;
map<int, bool> visited;

void dijkstra(int now, int nowMoney) {
    vector<int> sortNumber;

    for (int i = 0; i < loc[now][0].size(); i++) {
        if (money[loc[now][0][i]] == INF || money[loc[now][0][i]] > nowMoney + loc[now][1][i]) {
            money[loc[now][0][i]] = nowMoney + loc[now][1][i];
        }
        
        if (sortNumber.empty()) {
            sortNumber.push_back(i);
        } else {
            bool inserted = false;
            for (int j = 0; j < sortNumber.size(); j++) {
                if (loc[now][1][sortNumber[j]] > loc[now][1][i]) {
                    sortNumber.insert(sortNumber.begin(), i);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                sortNumber.push_back(i);
            }
        }
    }

    for (int i = 0; i < sortNumber.size(); i++) {
        if (visited[loc[now][0][sortNumber[i]]]) {
            return;
        }
        
        visited[loc[now][0][sortNumber[i]]] = true;
        dijkstra(loc[now][0][sortNumber[i]], nowMoney+loc[now][1][sortNumber[i]]);
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (vector<int> fare : fares) {
        if (loc[fare[0]].empty()) {
            loc[fare[0]] = vector<vector<int>>{{}, {}};
            money[fare[0]] = INF;
        }

        if (loc[fare[1]].empty()) {
            loc[fare[1]] = vector<vector<int>>{{}, {}};
            money[fare[1]] = INF;
        }

        loc[fare[0]][0].push_back(fare[1]);
        loc[fare[0]][1].push_back(fare[2]);
        loc[fare[1]][0].push_back(fare[0]);
        loc[fare[1]][1].push_back(fare[2]);
    }

    money[s] = 0;
    visited[s] = true;
    
    dijkstra(s, 0);
    int lowMoney = money[a] + money[b];

    loc.clear();
    money.clear();
    visited.clear();

    return lowMoney;
}

int main() {
    cout << solution(6, 4, 6, 2, vector<vector<int>>{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    cout << solution(7, 3, 4, 1, vector<vector<int>>{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    cout << solution(6, 4, 5, 6, vector<vector<int>>{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}}) << endl;
    
    return 0;
}

// 정확성은 있는데, 효율성은 떨어짐