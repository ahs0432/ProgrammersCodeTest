#include <string>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 아... stoi는 부호까지 처리를 대신해준다...
int solution(string s) {
    if (s[0] >= '0' && s[0] <= '9') {
        return stoi(s);
    } else if (s[0] == '-') {
        s.erase(s.begin());
        return -stoi(s);
    } else {
        s.erase(s.begin());
        return stoi(s);
    }
}