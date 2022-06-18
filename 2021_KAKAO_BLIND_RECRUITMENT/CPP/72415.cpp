#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int cardMove(vector<vector<int>> board, int src, int dst, int otherLoc, bool type) {
    int result = 0;

    if (type) {
        bool dstChange = false;
        if (dst < src) {
            dstChange = true;
            int tmp = dst;
            dst = src;
            src = tmp;
        }

        bool oneTouch = false;
        if (dst == 3 || board[dst][otherLoc] != 0 || (dstChange && board[src][otherLoc] != 0)) {
            oneTouch = true;
        }

        for (int i = src+1; i <= dst; i++) {
            if (!oneTouch) {
                result++;
                continue;
            }

            if (board[i][otherLoc] != 0) {
                result++;
            }
        }

        if (result == 0) {
            result = 1;
        }
    } else {
        bool dstChange = false;
        if (dst < src) {
            dstChange = true;
            int tmp = dst;
            dst = src;
            src = tmp;
        }

        bool oneTouch = false;
        if (dst == 3 || board[otherLoc][dst] != 0 || (dstChange && board[otherLoc][src] != 0)) {
            oneTouch = true;
        }

        for (int i = src+1; i <= dst; i++) {
            if (!oneTouch) {
                result++;
                continue;
            }

            if (board[otherLoc][i] != 0) {
                result++;
                continue;
            }
        }

        if (result == 0) {
            result = 1;
        }
    }

    return result;
}

int cardMoveCalc(vector<vector<int>> board, vector<int> src, vector<int> dst) {
    if (dst[0] == src[0] && dst[1] == src[1]) {
        return 0;
    }

    int xStart = 0;
    int yStart = 0;

    if (dst[0] != src[0]) {
        xStart += cardMove(board, src[0], dst[0], src[1], true);
        if (dst[1] != src[1]) yStart += cardMove(board, src[0], dst[0], dst[1], true);
    }

    if (dst[1] != src[1]) {
        yStart += cardMove(board, src[1], dst[1], src[0], false);
        if (dst[0] != src[0]) xStart += cardMove(board, src[1], dst[1], dst[0], false);
    }

    if (xStart == 0 && yStart == 0) {
        return 0;
    } else if (xStart == 0) {
        return yStart;
    } else if (yStart == 0) {
        return xStart;
    } else if (xStart <= yStart) {
        return xStart;
    }

    return yStart;
}

int calcCard(vector<vector<int>> board, vector<int> cardList, map<int, vector<vector<int>>> cardLocation, vector<int> nowLoc, int cardNum, int count) {
    cardList.erase(cardList.begin() + cardNum);

    int lowCount = 0;
    for (int i = 0; i < cardList.size(); i++) {
        int move1 = calcCard(board, cardList, cardLocation, cardLocation[cardList[i]][1], i, count + cardMoveCalc(board, nowLoc, cardLocation[cardList[i]][0]) + cardMoveCalc(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1]) + 2);
        int move2 = calcCard(board, cardList, cardLocation, cardLocation[cardList[i]][0], i, count + cardMoveCalc(board, nowLoc, cardLocation[cardList[i]][1]) + cardMoveCalc(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0]) + 2);

        int tmpCount = 0;
        if (move1 <= move2) {
            tmpCount = move1;
        } else {
            tmpCount = move2;
        }

        if (lowCount == 0 || tmpCount < lowCount) {
            lowCount = tmpCount;
        }
    }
    
    if (lowCount == 0) return count;
    return lowCount;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    vector<int> cardList = vector<int>{};
    map<int, vector<vector<int>>> cardLocation;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                continue;
            }

            if (cardLocation[board[i][j]].empty()) {
                cardList.push_back(board[i][j]);
                cardLocation[board[i][j]] = vector<vector<int>>{{i, j}};
            } else {
                cardLocation[board[i][j]].push_back(vector<int>{i, j});
            }
        }
    }

    for (int i = 0; i < cardList.size(); i++) {
        int move1 = calcCard(board, cardList, cardLocation, cardLocation[cardList[i]][1], i, cardMoveCalc(board, vector<int>{r,c}, cardLocation[cardList[i]][0]) + cardMoveCalc(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1]) + 2);
        int move2 = calcCard(board, cardList, cardLocation, cardLocation[cardList[i]][0], i, cardMoveCalc(board, vector<int>{r,c}, cardLocation[cardList[i]][1]) + cardMoveCalc(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0]) + 2);

        int tmpCount = 0;
        if (move1 <= move2) {
            tmpCount = move1;
        } else {
            tmpCount = move2;
        }

        if (answer == 0 || tmpCount < answer) {
            answer = tmpCount;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<vector<int>>{{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}}, 1, 0) << endl;
    cout << solution(vector<vector<int>>{{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}}, 1, 0) << endl;
    return 0;
}