#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// 정확도 100%, 효율성 100%
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++) {
        if (phone_book[i].size() <= phone_book[i-1].size()) {
            continue;
        }

        if (phone_book[i].substr(0, phone_book[i-1].size()) == phone_book[i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << solution(vector<string>{"119", "97674223", "1195524421"}) << endl;
    cout << solution(vector<string>{"123","456","789"}) << endl;
    cout << solution(vector<string>{"12","123","1235","567","88"}) << endl;

    return 0;
}