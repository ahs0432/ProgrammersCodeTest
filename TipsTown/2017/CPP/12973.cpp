#include <string>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(string s) {
    if (s.size() % 2) {
        return 0;
    }
    
    string stack = "";
    
    while (s.size() != 0) {
        if (stack.back() == s.back()) {
            stack.pop_back();
            s.pop_back();
            continue;
        }
        
        stack.push_back(s.back());
        s.pop_back();
    }

    return stack.size() == 0 ? 1 : 0;
}

int main() {
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;

    return 0;
}