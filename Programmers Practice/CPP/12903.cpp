#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(string s) {
    if (s.size() % 2 == 0) {
        return s.substr(s.size()/2-1, 2);
    } else {
        return s.substr(s.size()/2, 1);
    }
}