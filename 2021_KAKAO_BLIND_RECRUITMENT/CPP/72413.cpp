#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    map<int, vector<vector<int>>> loc;

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

    int answer = 0;

    return answer;
}

int main() {
    cout << solution(6, 4, 6, 2, vector<vector<int>>{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    //cout << solution(7, 3, 4, 1, vector<vector<int>>{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    //cout << solution(6, 4, 5, 6, vector<vector<int>>{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}}) << endl;
    
    return 0;
}