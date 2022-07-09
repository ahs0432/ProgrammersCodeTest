#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<string> numList = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int solution(string s) {
    string answer = "";

    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            answer += s[i];
        } else {
            for (int j = 0; j < numList.size(); j++) {
                bool strTrue = true;
                for (int k = 0; k < numList[j].size(); k++) {
                    if (s[i + k] != numList[j][k]) {
                        strTrue = false;
                        break;
                    }
                }

                if (strTrue) {
                    i += numList[j].size() - 1;
                    answer += to_string(j);
                    break;
                }
            }
        }
    }

    return stoi(answer);
}

int main() {
    cout << solution("one4seveneight") << endl;
    cout << solution("23four5six7") << endl;
    cout << solution("2three45sixseven") << endl;
    cout << solution("123") << endl;

    return 0;
}