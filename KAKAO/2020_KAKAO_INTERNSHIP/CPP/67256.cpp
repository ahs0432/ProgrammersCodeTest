#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lastRight = 10;
    int lastLeft = 12;

    for (int number : numbers) {
        if (number == 1 || number == 4 || number == 7) {
            answer += "L";
            lastLeft = number;
        } else if (number == 3 || number == 6 || number == 9) {
            answer += "R";
            lastRight = number;
        } else {
            if (number == 0) {
                number = 11;
            }

            if (lastLeft == number) {
                lastLeft = number;
                answer += "L";
            } else if (lastRight == number) {
                lastRight = number;
                answer += "R";
            } else {
                int cLeft = (abs(lastLeft - number) / 3) + (abs(lastLeft - number) % 3);
                int cRight = (abs(lastRight - number) / 3) + (abs(lastRight - number) % 3);

                if (cLeft < cRight) {
                    answer += "L";
                    lastLeft = number;
                } else if (cLeft > cRight) {
                    answer += "R";
                    lastRight = number;
                } else {
                    if (hand == "left") {
                        answer += "L";
                        lastLeft = number;
                    } else {
                        answer += "R";
                        lastRight = number;
                    }
                }
            }
        }
    }
    return answer;
}

int main() {
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;
    cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left") << endl;
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right") << endl;

    return 0;
}