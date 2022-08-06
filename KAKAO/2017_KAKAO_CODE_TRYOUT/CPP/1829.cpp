#include <vector>
#include <queue>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int area = 0;
    int max = 0;
    vector<pair<int, int>> moveLocs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    vector<vector<bool>> check(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || check[i][j]) {
                continue;
            }
            
            area++;
            int count = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            int nowColor = picture[i][j];
            
            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                
                if (check[y][x]) {
                    q.pop();
                    continue;
                }
                
                check[y][x] = true;
                
                for (pair<int, int> moveLoc : moveLocs) {
                    int moveY = y + moveLoc.first;
                    int moveX = x + moveLoc.second;
                    
                    if (moveY < 0 || moveX < 0 || moveY >= m || moveX >= m || check[moveY][moveX] || picture[moveY][moveX] != nowColor) {
                        continue;
                    }
                    q.push({moveY, moveX});
                }
                count++;
                q.pop();
            }
            
            if (count > max) {
                max = count;
            }
        }
    }
    
    return {area, max};
}