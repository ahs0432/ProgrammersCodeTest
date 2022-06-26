#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 정확성 100% / Timeout
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for (int i = 0; i < prices.size(); i++) {
        int min = *min_element(prices.begin() + i, prices.end());
        if (prices[i] == min) {
            answer[i] = prices.size() - 1 - i;
        } else {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[i] > prices[j]) {
                    answer[i] = j - i;
                    break;
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

    return 0;
}