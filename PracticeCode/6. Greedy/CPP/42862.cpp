#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<bool> amount(n, true);

    for (int l : lost) {
        amount[l-1] = false;
    }

    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++) {
        int r = reserve[i] - 1;
        if (!amount[r]) {
            reserve.erase(reserve.begin() + i);
            amount[r] = true;
            answer++;
            i--;
        }
    }

    for (int r : reserve) {
        r -= 1;
        if (r != 0 && !amount[r-1]) {
            amount[r-1] = true;
            answer++;
        } else if (r != (n-1) && !amount[r+1]) {
            amount[r+1] = true;
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(5, vector<int>{2, 4}, vector<int>{1, 3, 5}) << endl;
    cout << solution(7, vector<int>{2, 3, 4}, vector<int>{1, 2, 3, 6}) << endl;
    cout << solution(5, vector<int>{2, 4}, vector<int>{3}) << endl;
    cout << solution(3, vector<int>{3}, vector<int>{1}) << endl;
}