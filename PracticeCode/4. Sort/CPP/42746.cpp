#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 각 수의 가장 앞자리 수가 높은 순서대로 정렬하고 만약 같다면 다음 숫자가 높은 순대로 정렬하여 문자열로 Return
bool compare(int i, int j) {
    string iStr = to_string(i);
    string jStr = to_string(j);

    if (iStr.size() == jStr.size()) {
        return i > j;
    }

    string total1 = iStr + jStr;
    string total2 = jStr + iStr;

    return stoi(total1) > stoi(total2);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);

    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        if (i == 0 && numbers[i] == 0) {
            answer = "0";
            break;
        }
        answer += to_string(numbers[i]);
    }
    return answer;
}

int main() {
    cout << solution(vector<int>{6, 10, 2}) << endl;
    cout << solution(vector<int>{3, 30, 34, 5, 9}) << endl;
    cout << solution(vector<int>{23, 232, 21, 212}) << endl;
}