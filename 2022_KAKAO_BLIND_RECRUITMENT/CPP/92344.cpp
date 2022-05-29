#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector< vector<int> > board, vector< vector<int> > skill) {
    vector<int>* skillT = skill.data();
    vector<int>* boardT = board.data();

    for (int i = 0; i < skill.size(); i++) {
        int* skillTmp = skillT[i].data();
        if (skillTmp[0] == 1) {
            for (int j = skillTmp[1]; j <= skillTmp[3]; j++) {
                int* boardTmp = boardT[j].data();
                for (int k = skillTmp[2]; k <= skillTmp[4]; k++) {
                   boardTmp[k] = boardTmp[k] - skillTmp[5];
                }
            }
        } else {
            for (int j = skillTmp[1]; j <= skillTmp[3]; j++) {
                int* boardTmp = boardT[j].data();
                for (int k = skillTmp[2]; k <= skillTmp[4]; k++) {
                   boardTmp[k] = boardTmp[k] + skillTmp[5];
                }
            }
        }
    }
    
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        int* boardTmp = boardT[i].data();
        for (int j = 0; j < board[i].size(); j++) {
            if (boardTmp[j] > 0) {
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

