#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;

    for (int move : moves) {
        move -= 1;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][move] != 0) {
                if (!bucket.empty() && bucket.back() == board[i][move]) {
                    answer += 2;
                    bucket.pop_back();
                } else {
                    bucket.push_back(board[i][move]);
                }
                board[i][move] = 0;

                break;
            }
        }

    }

    return answer;
}

int main() {   
    cout << solution(vector<vector<int>>{{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}}, vector<int>{1,5,3,5,1,2,1,4}) << endl;
}