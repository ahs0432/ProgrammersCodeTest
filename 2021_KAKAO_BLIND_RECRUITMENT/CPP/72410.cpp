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
    char backChar = 0;
    for (int i = 1; i < new_id.size(); i++) {
        char backChar = new_id[i-1];
        if (backChar == '.' && new_id[i] == '.' ) {
            new_id[i-1] = 0;
        }
    }
    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");

    // 4 Step
    if (new_id[0] == '.') {
        new_id[0] = 0;
    }
    if (new_id[new_id.size()-1] == '.') {
        new_id[new_id.size()-1] = 0;
    }

    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");

    // 5 Step
    if (new_id.size() == 0) {
        new_id = "a";
    // 6 Step
    } else if (new_id.size() > 15) {
        if (new_id[14] == '.') {
            new_id[14] = 0;
        }
        for (int i = 15; i < new_id.size(); i++) {
            new_id[i] = 0;
        }
        new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");
    } 

    // 7 Step
    if (new_id.size() < 3) {
        char a = new_id[new_id.size()-1];
        for (int i = new_id.size(); i < 3; i++) {
            new_id+=a;
        }
    }

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