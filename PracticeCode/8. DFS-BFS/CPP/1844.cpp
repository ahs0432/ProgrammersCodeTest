#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 정확도 100%, 효율성 0%
int solution(vector<vector<int>> maps) {
    int xmax = (maps.size() - 1);
    int ymax = (maps[0].size() - 1);
    
    // nowloc, count
    queue<pair<vector<int>, int>> q;
    q.push({{0, 0}, 1});

    int count = -1;

    while(!q.empty()) {
        maps[q.front().first[0]][q.front().first[1]] = 0;

        if (q.front().first[0] == xmax && q.front().first[1] == ymax) {
            return q.front().second;
        }

        if (q.front().first[0] != 0 && maps[q.front().first[0] - 1][q.front().first[1]]) {
            q.push({{q.front().first[0] - 1, q.front().first[1]}, (q.front().second + 1)});
        }

        if (q.front().first[1] != 0 && maps[q.front().first[0]][q.front().first[1] - 1]) {
            q.push({{q.front().first[0], q.front().first[1] - 1}, (q.front().second + 1)});
        }

        if (q.front().first[0] != xmax && maps[q.front().first[0] + 1][q.front().first[1]]) {
            q.push({{q.front().first[0] + 1, q.front().first[1]}, (q.front().second + 1)});
        }

        if (q.front().first[1] != ymax && maps[q.front().first[0]][q.front().first[1] + 1]) {
            q.push({{q.front().first[0], q.front().first[1] + 1}, (q.front().second + 1)});
        }

        q.pop();
    }

    return count;
}

int main() {
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}) << endl;
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}}) << endl;

    return 0;
}