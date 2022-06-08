#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1 Step
    for (int i = 0; i < new_id.size(); i++) {
        if ('A' <= new_id[i] && 'Z' >= new_id[i]) {
            new_id[i] += 32;
        }
    }

    // 2 Step
    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");

    // 3 Step
    for (int i = 0; i < new_id.size(); i++) {
        if (!answer.empty() && answer.back() == '.' && new_id[i] == '.') {
            continue;
        }
        answer += new_id[i];
    }

    // 4 Step
    if (answer.front() == '.') {
        answer.erase(answer.begin());
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }

    // 5 Step
    if (answer.empty()) {
        answer = "a";
    // 6 Step
    } else if (answer.size() > 15) {
        answer = answer.substr(0, 15);
        if (answer.back() == '.') {
            answer.pop_back();
        }
    } 

    // 7 Step
    if (answer.size() < 3) {
        for (int i = answer.size(); i < 3; i++) {
            answer+=answer.back();
        }
    }

    return answer;
}

int main() {
    cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("=.=") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;

    return 0;
}