#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 정확도 80%
int cardMove(vector<vector<int>> board, vector<int> src, vector<int> dst, bool type, int count) {
    if (src[0] == dst[0] && src[1] == dst[1]) {
        return count;
    } else if (src[type] == dst[type]) {
        return cardMove(board, src, dst, !type, count);
    }

    int lowCount = 0;
    bool oneTouch = false;
    int oneTouchTarget = 0;
    int oneTouchCount = 0;

    for (int i = 1; i <= abs(dst[type]-src[type]); i++) {
        int absCount = i;
        if (dst[type] < src[type]) {
            absCount = -absCount;
        }

        if (type && board[src[!type]][src[type]+absCount] == 0) {
            oneTouch = true;
        } else if (!type && board[src[type]+absCount][src[!type]] == 0) {
            oneTouch = true;
        } else if (oneTouch && oneTouchTarget == 0 && type && (src[type]+absCount == 3 || src[type]+absCount == 0 || board[src[!type]][src[type]+absCount] != 0)) {
            oneTouchTarget = i;
            oneTouchCount += 1;
            break;
        } else if (oneTouch && oneTouchTarget == 0 && !type && (src[type]+absCount == 3 || src[type]+absCount == 0 || board[src[type]+absCount][src[!type]] != 0)) {
            oneTouchTarget = i;
            oneTouchCount += 1;
            break;
        } else {
            oneTouchCount += 1;
        }
    }

    for (int i = 1; i <= abs(dst[type]-src[type]); i++) {
        int addCount = 0;
        int moving = i;
        if (oneTouchTarget == i) {
            addCount = oneTouchCount;
        } else if (oneTouch && oneTouchTarget < i) {
            addCount = oneTouchCount + 1;
        } else {
            addCount = i;
        }

        if (dst[type] < src[type]) {
            moving = -moving;
        } 

        src[type] += moving;
        int tmpCount = cardMove(board, src, dst, !type, count+addCount);
        if (lowCount == 0 || tmpCount < lowCount) {
            lowCount = tmpCount;
        }
        src[type] -= moving;
    }
    
    return lowCount;
}

int compareMove(int move1, int move2) {
    if (move1 <= move2) {
        return move1;
    } else {
        return move2;
    }
}

int calcMove(vector<vector<int>> board, vector<int> cardList, map<int, vector<vector<int>>> cardLocation, vector<int> nowLoc, int cardNum, int count) {
    for (vector<int> loc : cardLocation[cardList[cardNum]]) {
        board[loc[0]][loc[1]] = 0;
    }
    
    cardList.erase(cardList.begin() + cardNum);
    if (cardList.size() == 0) {
        return count;
    }

    int lowCount = 0;
    
    for (int i = 0; i < cardList.size(); i++) {
        int move = compareMove(
            calcMove(board, cardList, cardLocation, cardLocation[cardList[i]][1], i, 
                count + compareMove(cardMove(board, nowLoc, cardLocation[cardList[i]][0], true, 0), cardMove(board, nowLoc, cardLocation[cardList[i]][0], false, 0))
                + compareMove(cardMove(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1], true, 2), cardMove(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1], false, 2))),
            calcMove(board, cardList, cardLocation, cardLocation[cardList[i]][0], i, 
                count + compareMove(cardMove(board, nowLoc, cardLocation[cardList[i]][1], true, 0), cardMove(board, nowLoc, cardLocation[cardList[i]][1], false, 0))
                + compareMove(cardMove(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0], true, 2), cardMove(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0], false, 2))));

        if (lowCount == 0 || lowCount > move) {
            lowCount = move;
        }
       
    }

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

    for (int i = 0; i< cardList.size(); i++) {
        int move = compareMove(
            calcMove(board, cardList, cardLocation, cardLocation[cardList[i]][1], i, 
                compareMove(cardMove(board, vector<int>{r, c}, cardLocation[cardList[i]][0], true, 0), cardMove(board, vector<int>{r, c}, cardLocation[cardList[i]][0], false, 0))
                + compareMove(cardMove(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1], true, 2), cardMove(board, cardLocation[cardList[i]][0], cardLocation[cardList[i]][1], false, 2))),
            calcMove(board, cardList, cardLocation, cardLocation[cardList[i]][0], i, 
                compareMove(cardMove(board, vector<int>{r, c}, cardLocation[cardList[i]][1], true, 0), cardMove(board, vector<int>{r, c}, cardLocation[cardList[i]][1], false, 0))
                + compareMove(cardMove(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0], true, 2), cardMove(board, cardLocation[cardList[i]][1], cardLocation[cardList[i]][0], false, 2))));

        if (answer == 0 || answer > move) {
            answer = move;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<vector<int>>{{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}}, 1, 0) << endl;
    cout << solution(vector<vector<int>>{{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}}, 1, 0) << endl;
    cout << solution(vector<vector<int>>{{1,5,0,2},{6,4,3,0},{0,2,1,5},{3,0,6,4}}, 0, 0) << endl; // Answer 32;;;
    return 0;
}