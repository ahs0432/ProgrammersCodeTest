#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector< vector<int> > board, vector< vector<int> > skill) {
    vector< vector<int> > boardTotal(board.size()+1, vector<int>(board[0].size()+1, 0));

    for (vector<int> skl : skill) {
        if (skl[0] == 1) {
            boardTotal[skl[1]][skl[2]] += -skl[5];
            boardTotal[skl[3]+1][skl[4]+1] += -skl[5];
            boardTotal[skl[1]][skl[4]+1] += skl[5];
            boardTotal[skl[3]+1][skl[2]] += skl[5];
        } else {
            boardTotal[skl[1]][skl[2]] += skl[5];
            boardTotal[skl[3]+1][skl[4]+1] += skl[5];
            boardTotal[skl[1]][skl[4]+1] += -skl[5];
            boardTotal[skl[3]+1][skl[2]] += -skl[5];
        }
    }

    for (int i = 1; i < boardTotal.size(); i++) {
        for (int j = 0; j < boardTotal[0].size(); j++) {
            boardTotal[i][j] += boardTotal[i-1][j];
        }
    }

    for (int i = 1; i < boardTotal[0].size(); i++) {
        for (int j = 0; j < boardTotal.size(); j++) {
            boardTotal[j][i] += boardTotal[j][i-1];
        }
    }
    
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        int* boardTmp = board[i].data();
        for (int j = 0; j < board[i].size(); j++) {
            if (boardTmp[j]+boardTotal[i][j] > 0) {
                answer++;
            }
        }
    }

    return answer;
}

/*
    for (vector<int> num : skillTmp) {
        if (num[0] == 1) {
           for (int i = num[1]; i <= num[3]; i++) {
               for (int j = num[2]; j <= num[4]; j++) {
                   board[i][j] = board[i][j] - num[5];
               }
           } 
        } else {
            for (int i = num[1]; i <= num[3]; i++) {
               for (int j = num[2]; j <= num[4]; j++) {
                   board[i][j] = board[i][j] + num[5];
               }
           } 
        }
    }

    int answer = 0;

    for (int i = 0; i < board[0].size()*board.size(); i++) {
        if (i==0) {
            if (board[0][0] > 0) {
                answer++;
            }
            continue;
        }

        if (board[i/board[0].size()][i%board[0].size()] > 0) {
            answer++;
        }
    }

    return answer;
}
*/

int main() {
    vector< vector<int> > q1_v1(4, vector<int>(5, 5));
    vector< vector<int> > q1_v2({ { 1,0,0,3,4,4 }, { 1,2,0,2,3,2 }, { 2,1,0,3,1,2 }, { 1,0,1,3,3,1 } });
    cout << solution(q1_v1, q1_v2) << endl;

    vector< vector<int> > q2_v1({{1,2,3}, {4,5,6}, {7,8,9}});
    vector< vector<int> > q2_v2({ {1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100} });
    cout << solution(q2_v1, q2_v2) << endl;
    
    return 0;
}

