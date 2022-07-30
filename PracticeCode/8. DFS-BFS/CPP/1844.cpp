#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 정확도 100%, 효율성 100%
int solution(vector<vector<int>> maps) {
    int xmax = (maps.size() - 1);
    int ymax = (maps[0].size() - 1);

    vector<pair<int, int>> moveLoc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // nowloc, count
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    maps[0][0] = 0;

    while(!q.empty()) {
        if (q.front().first.first == xmax && q.front().first.second == ymax) {
            return q.front().second;
        }

        for (pair<int, int> m : moveLoc) {
            int nextX = q.front().first.first + m.first;
            int nextY = q.front().first.second + m.second;

            if ((nextX < 0 || nextY < 0 || nextX > xmax || nextY > ymax) || maps[nextX][nextY] == 0 ) {
                continue;
            }

            maps[nextX][nextY] = 0;
            q.push({{nextX, nextY}, q.front().second + 1});
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