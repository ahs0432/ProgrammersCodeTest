#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 104로 수정 필요
    vector<vector<bool>> cordis(104, vector<bool>(104, false));

    // 우선 사각형을 먼저 판에 나타냄
    for (vector<int> rec : rectangle) {
        for (int i = rec[0] * 2; i <= rec[2] * 2; i++) {
            for (int j = rec[1] * 2; j <= rec[3] * 2; j++) {
                cordis[i][j] = true;
            }
        }
    }

    for (vector<int> rec : rectangle) {
        for (int i = rec[0] * 2 + 1; i <= rec[2] * 2 - 1; i++) {
            for (int j = rec[1] * 2 + 1; j <= rec[3] * 2 - 1; j++) {
                cordis[i][j] = false;
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0.0, {characterX * 2, characterY * 2}});
    vector<pair<int, int>> moveLoc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while(!q.empty()) {
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        int nowCount = q.front().first;

        cordis[nowX][nowY] = false;
        if (nowX == (itemX * 2) && nowY == (itemY * 2)) {
            return nowCount / 2;
        }

        for (pair<int, int> ml : moveLoc) {
            int nextX = nowX + ml.first;
            int nextY = nowY + ml.second;

            if (nextX > 103 || nextY > 103 || nextX < 0 || nextY < 0 || !cordis[nextX][nextY]) {
                continue;
            }

            q.push({nowCount + 1, {nextX, nextY}});
        }

        q.pop();
    }

    return -1;
}

int main() {
    cout << solution({{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}}, 1, 3, 7, 8) << endl;
    cout << solution({{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}}, 9, 7, 6, 1) << endl;
    cout << solution({{1, 1, 5, 7}}, 1, 1, 4, 7) << endl;
    cout << solution({{2, 1, 7, 5}, {6, 4, 10, 10}}, 3, 1, 7, 10) << endl;
    cout << solution({{2, 2, 5, 5}, {1, 3, 6, 4}, {3, 1, 4, 6}}, 1, 4, 6, 3) << endl;

    return 0;
}