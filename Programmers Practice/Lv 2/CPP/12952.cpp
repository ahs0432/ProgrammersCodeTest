#include <vector>

using namespace std;

vector<vector<bool>> boardSet(vector<vector<bool>> board, int col, int row, int n) {
    for (int i = 0; i < n; i++) {
        if (row - (col - i) >= 0 && row - (col - i) < n) {
            board[i][row - (col - i)] = true;
        }
        
        if (row + (col - i) >= 0 && row + (col - i) < n) {
            board[i][row + (col - i)] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        board[col][i] = true;
        board[i][row] = true;
    }
    
    return board;
}

int dfs(vector<vector<bool>> board, int n, int c) {    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!board[c][i]) {
            if ((c + 1) == n) {
                answer += 1;
                continue;
            }
            
            answer += dfs(boardSet(board, c, i, n), n, c + 1);
        }
    }
    
    return answer;
}

int solution(int n) {
    if (n == 1) {
        return 1;
    } else if (n <= 3) {
        return 0;
    }
    
    vector<vector<bool>> board(n, vector<bool>(n));
    
    int answer = dfs(board, n, 0);
    
    return answer;
}