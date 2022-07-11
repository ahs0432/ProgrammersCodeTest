#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAX = 8;
vector<vector<int>> calcList(MAX);

// 정확도 77.8% / TC 5, 8 
int dfs(int N, int number, int count) {
    if (count >= MAX) {
        return -1;
    }

    for (int i = 0; i < (count - 1); i++) {
        for (int calcI : calcList[i]) {
            for (int calcJ : calcList[(count - 1) - i - 1]) {
                if (number == (calcI + calcJ)) {
                    return count;
                } else if (number == (calcI * calcJ)) {
                    return count;
                }

                calcList[count - 1].push_back(calcI + calcJ);
                calcList[count - 1].push_back(calcI * calcJ);

                if (calcI >= calcJ) {
                    if (number == (calcI - calcJ)) {
                        return count;
                    }

                    calcList[count - 1].push_back(calcI - calcJ);
                    if (calcI > 0 && calcJ > 0 && calcI % calcJ == 0) {
                        if (number == (calcI / calcJ)) {
                            return count;
                        }
                        calcList[count - 1].push_back(calcI / calcJ);
                    }
                }
            }
        }
    }

    int answer = dfs(N, number, count + 1);

    return answer;
}

int solution(int N, int number) {
    int pushNumber = 0;
    for (int i = 1; i <= MAX; i++) {
        if (i == 1) {
            pushNumber = N;
        } else {
            pushNumber = stoi(to_string(pushNumber) + to_string(N));
        }

        calcList[(i - 1)].push_back(pushNumber);

        if (pushNumber == number) {
            return i;
        }
    }

    if (number > pushNumber) {
        return -1;
    }

    return dfs(N, number, 2);
}

int main() {
    cout << solution(5, 12) << endl;

    calcList = vector<vector<int>>(8);
    cout << solution(2, 11) << endl;
}