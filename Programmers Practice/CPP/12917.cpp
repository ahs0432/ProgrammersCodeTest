#include <string>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(string s) {
    sort(s.begin(), s.end(), greater());
    return s;
}