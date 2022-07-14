#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> nowMap(n, vector<int>(m, 0));
    
    for (vector<int> puddle : puddles) {
        nowMap[puddle[1]-1][puddle[0]-1] = -1;
    }
    nowMap[0][0] = 1;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (nowMap[i][j] != -1) {
                if (i >= 1 && nowMap[i-1][j] != -1) {
                    nowMap[i][j] += nowMap[i-1][j];
                }
                if (j >= 1 && nowMap[i][j-1] != -1) {
                    nowMap[i][j] += nowMap[i][j-1];
                }
            }

            if (nowMap[i][j] >= 1000000007) {
                nowMap[i][j] %= 1000000007;
            }
        }
    }

    return nowMap[n-1][m-1];
}

int main() {
    cout << solution(4, 3, vector<vector<int>>{{2, 2}}) << endl;
    cout << solution(2, 2, vector<vector<int>>{{1,0},{0,1}}) << endl;

    return 0;
}