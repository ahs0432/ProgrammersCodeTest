#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 정확도 100%, 효율성 50%
int solution(vector<vector<int>> maps) {
    int xmax = (maps.size() - 1);
    int ymax = (maps[0].size() - 1);

    vector<vector<int>> moveLoc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // nowloc, count
    queue<pair<vector<int>, int>> q;
    q.push({{0, 0}, 1});
    maps[0][0] = 0;

    while(!q.empty()) {
        if (q.front().first[0] == xmax && q.front().first[1] == ymax) {
            return q.front().second;
        }

        int nextCount = q.front().second + 1;

        for (vector<int> m : moveLoc) {
            int nextX = q.front().first[0] + m[0];
            int nextY = q.front().first[1] + m[1];

            if (nextX < 0 || nextY < 0 || nextX > xmax || nextY > ymax || maps[nextX][nextY] == 0) {
                continue;
            }

            maps[nextX][nextY] = 0;
            q.push({{nextX, nextY}, nextCount});
        }

        q.pop();
    }

    return -1;
}

int main() {
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}) << endl;
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}}) << endl;

    return 0;
}