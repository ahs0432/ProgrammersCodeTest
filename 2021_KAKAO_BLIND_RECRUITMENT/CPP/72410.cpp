#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        if ('A' <= new_id[i] && 'Z' >= new_id[i]) {
            new_id[i] += 32;
        }
    }

    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");
    answer = new_id;
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