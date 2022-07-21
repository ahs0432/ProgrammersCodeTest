#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(int n, int k, int count, vector<vector<int>> dungeons) {
    if (n != -1) {
        k -= dungeons[n][1];
        dungeons.erase(dungeons.begin() + n);
        count++;
    }

    int maxCount = count;

    for (int i = 0; i < dungeons.size(); i++) {
        if (dungeons[i][0] <= k) {
            int tmpCount = dfs(i, k, count, dungeons);
            if (tmpCount > maxCount) {
                maxCount = tmpCount;
            }
        }
    }

    return maxCount;
}

int solution(int k, vector<vector<int>> dungeons) {
    return dfs(-1, k, 0, dungeons);
}

int main() {
    cout << solution(80, {{80,20},{50,40},{30,10}}) << endl;
    return 0;
}