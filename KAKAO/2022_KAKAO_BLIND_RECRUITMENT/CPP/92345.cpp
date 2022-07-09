#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>> ableLocCalc(vector<vector<int>> board, vector<int> loc) {
    vector<vector<int>> ableLoc;

	if (loc[0] != 0 && board[loc[0]-1][loc[1]] != 0) {
        ableLoc.push_back(vector<int>{loc[0]-1,loc[1]});
	}
	if (loc[0] != board.size()-1 && board[loc[0]+1][loc[1]] != 0) {
        ableLoc.push_back(vector<int>{loc[0]+1,loc[1]});
	}
	if (loc[1] != 0 && board[loc[0]][loc[1]-1] != 0) {
        ableLoc.push_back(vector<int>{loc[0],loc[1]-1});
	}
	if (loc[1] != board[0].size()-1 && board[loc[0]][loc[1]+1] != 0) {
        ableLoc.push_back(vector<int>{loc[0],loc[1]+1});
	}

	return ableLoc;
}

tuple<bool, int> playerLocation(vector<vector<int>> board, vector<int> myloc, vector<int> oploc) {
    vector<vector<int>> ableLoc = ableLocCalc(board, myloc);
    if (ableLoc.empty()) {
        return tuple<bool, int>(false, 0);
    }

    if (myloc[0] == oploc[0] && myloc[1] == oploc[1]) {
        return tuple<bool, int>(true, 1);
    }

    bool canWin = false;
    int totalRate = 0;

    for (vector<int> &loc : ableLoc) {
        board[myloc[0]][myloc[1]] = 0;
        tuple<bool, int> rest = playerLocation(board, oploc, loc);
        board[myloc[0]][myloc[1]] = 0;

        if (!get<0>(rest)) {
            if (!canWin) {
                canWin = true;
                totalRate = get<1>(rest);
            } else {
                if (get<1>(rest) < totalRate) {
                    totalRate = get<1>(rest);
                }
            }
        } else {
            if (canWin) {
                continue;
            } else {
                if (get<1>(rest) > totalRate) {
                    totalRate = get<1>(rest);
                }
            }
        }
    }
    totalRate+=1;

    return tuple<bool, int>(canWin, totalRate);
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    tuple<bool, int> result = playerLocation(board, aloc, bloc);
    return get<1>(result);
}