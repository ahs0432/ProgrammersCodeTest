#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> boards = vector<vector<bool>>(m, vector<bool>(n, false));
    
    while (true) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char nowChar = board[i][j];
                if (nowChar == ' ') {
                    continue;
                }

                if (nowChar == board[i + 1][j] && nowChar == board[i][j + 1] 
                    && nowChar == board[i + 1][j + 1]) {
                    boards[i][j] = true;
                    boards[i + 1][j] = true;
                    boards[i][j + 1] = true;
                    boards[i + 1][j + 1] = true;
                }
            }
        }

        bool deleted = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (boards[i][j]) {
                    answer++;
                    deleted = true;

                    for (int k = i; k > 0; k--) {
                        board[k][j] = board[k - 1][j];
                    }
                    board[0][j] = ' ';
                }
            }
        }
        
        if (!deleted) {
            break;
        }
        boards = vector<vector<bool>>(m, vector<bool>(n, false));
    }
    
    return answer;
}