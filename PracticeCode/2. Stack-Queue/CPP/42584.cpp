#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// Stack을 이용한 풀이 방법이 존재하니 확인
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    int minLoc = 0;

    for (int i = prices.size()-1; i >= 0 ; i--) {
        if (i == prices.size()-1) {
            minLoc = i;
        } else {
            if (prices[minLoc] >= prices[i]) {
                minLoc = i;
                answer[i] = (prices.size() - 1) - i;
            } else {
                for (int j = i+1; j <= minLoc; j++) {
                    if (prices[j] < prices[i]) {
                        answer[i] = j - i;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}

int main() {
    for (int a : solution(vector<int>{1, 2, 3, 2, 3})) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(vector<int>{2121, 33, 11, 231, 22})) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}