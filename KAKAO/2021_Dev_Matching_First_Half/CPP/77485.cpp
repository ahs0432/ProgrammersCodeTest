#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer(queries.size(), 0);
    vector<vector<int>> board(rows, vector<int>(columns, 0));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j] = (i * columns) + (j + 1);
		}
	}

    int now = 0;
    for (vector<int> query : queries) {
        for (int i = 0; i < query.size(); i++) {
            query[i] -= 1;
        }

        int tmpData = board[query[0]][query[1]];
		int min = tmpData;

        for (int i = query[0]; i < query[2]; i++) {
			int val = board[i+1][query[1]];
			board[i][query[1]] = val;
			if (val < min) {
				min = val;
			}
		}

		for (int i = query[1]; i < query[3]; i++) {
			int val = board[query[2]][i+1];
			board[query[2]][i] = val;
			if (val < min) {
				min = val;
			}
		}

		for (int i = query[2]; i > query[0]; i--) {
			int val = board[i-1][query[3]];
			board[i][query[3]] = val;
			if (val < min) {
				min = val;
			}
		}

		for (int i = query[3]; i > query[1]; i--) {
			int val = board[query[0]][i-1];
			board[query[0]][i] = val;
			if (val < min) {
				min = val;
			}
		}
        board[query[0]][query[1]+1] = tmpData;
        
        answer[now] = min;
        now++;
    }

    return answer;
}

int main() {
    vector<vector<int>> q1({ {2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3} });
    for (int i : solution(6, 6, q1)) {
        cout << i << " ";
    }

    cout << endl;

    vector<vector<int>> q2({ {1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3} });
    for (int i : solution(3, 3, q2)) {
        cout << i << " ";
    }
    
    return 0;
}