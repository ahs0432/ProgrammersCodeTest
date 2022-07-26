#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> arrResult;
queue<vector<string>> arrs;

// 정확성 100%, 효율성 0%
void arrCalc(vector<string> arr) {
    if (arr.size() <= 3) {
        if (arr[1] == "+") {
            arrResult.push_back(stoi(arr[0]) + stoi(arr[2]));
        } else {
            arrResult.push_back(stoi(arr[0]) - stoi(arr[2]));
        }

        return;
    }

    vector<string> tmpArr = arr;
    for (int i = 0; i < arr.size() - 1;) {
        if (arr[i + 1] == "+") {
            arr[i] = to_string(stoi(arr[i]) + stoi(arr[i+2]));
        } else {
            arr[i] = to_string(stoi(arr[i]) - stoi(arr[i+2]));
        }

        arr.erase(arr.begin() + (i + 1));
        arr.erase(arr.begin() + (i + 1));
        arrs.push(arr);

        i += 2;
        arr = tmpArr;
    }
}

int solution(vector<string> arr) {
    arrs.push(arr);

    while (!arrs.empty()) {
        arrCalc(arrs.front());
        arrs.pop();
    }

    sort(arrResult.begin(), arrResult.end());
    return arrResult.back();
}

int main() {
    cout << solution({"1", "-", "3", "+", "5", "-", "8"}) << endl;
    cout << solution({"5", "-", "3", "+", "1", "+", "2", "-", "4"}) << endl;

    return 0;
}