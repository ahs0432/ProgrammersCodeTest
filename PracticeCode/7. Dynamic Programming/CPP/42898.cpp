#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 정확성 테스트 90% / TC 8 Timeout
int moveLoc(vector<vector<int>> nowMap, vector<int> nowLoc) {
    if (nowMap[nowLoc[1]][nowLoc[0]] == 1) {
        return 1;
    }

    int result = 0;
    if (nowLoc[1]+1 != nowMap.size() && nowMap[nowLoc[1]+1][nowLoc[0]] != -1) {
        result += moveLoc(nowMap, vector<int>{nowLoc[0], nowLoc[1]+1});
    }
    
    if (nowLoc[0]+1 != nowMap[0].size() && nowMap[nowLoc[1]][nowLoc[0]+1] != -1) {
        result += moveLoc(nowMap, vector<int>{nowLoc[0]+1, nowLoc[1]});
    }

    return result % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> nowMap(n, vector<int>(m, 0));
    
    for (vector<int> puddle : puddles) {
        nowMap[puddle[1]-1][puddle[0]-1] = -1;
    }
    nowMap[n-1][m-1] = 1;

    return moveLoc(nowMap, vector<int>{0,0});
}

int main() {
    cout << solution(4, 3, vector<vector<int>>{{2, 2}}) << endl;

    return 0;
}