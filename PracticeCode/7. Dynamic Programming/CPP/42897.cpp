#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// DP 점화식에 대한 더 많은 이해도가 필요할 것으로 보임.
int solution(vector<int> money) {
    vector<int> money1 = money;
    vector<int> money2 = money;

    money1.insert(money1.begin(), 0);
    money1.pop_back();
    money2[0] = 0;

    for (int i = 2; i < money1.size(); i++) {
        if (money1[i-1] < money1[i-2] + money1[i]) {
            money1[i] = money1[i-2] + money1[i];
            continue;
        }
        money1[i] = money1[i-1];
    }

    for (int i = 2; i < money2.size(); i++) {
        if (money2[i-1] < money2[i-2] + money2[i]) {
            money2[i] = money2[i-2] + money2[i];
            continue;
        }
        money2[i] = money2[i-1];
    }

    if (money1.back() < money2.back()) {
        return money2.back();
    }
    return money1.back();
}

int main() {
    cout << solution(vector<int>{1, 2, 3, 1}) << endl;
    cout << solution(vector<int>{0,0,0,0,100,0,0,100,0,0,1,1}) << endl; // 201
    cout << solution(vector<int>{1, 10, 20, 4, 40}) << endl; // 60
    cout << solution(vector<int>{1, 1, 4, 1, 4}) << endl; // 8
    cout << solution(vector<int>{1000, 1, 0, 1, 2, 1000, 0}) << endl; // 2001
    cout << solution(vector<int>{91, 90, 5, 7, 5, 7}) << endl; // 104

    return 0;
}