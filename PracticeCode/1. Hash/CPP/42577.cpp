#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// 정확도 100%, 효율성 75%
bool compareSort(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    sort(phone_book.begin(), phone_book.end(), compareSort);

    for (int i = 0; phone_book[i].size() < phone_book.back().size(); i++) {
        string s = phone_book[i];
        for (int j = i+1; j < phone_book.size(); j++) {
            if (phone_book[j].substr(0, s.size()) == s) {
                return false;
            }
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