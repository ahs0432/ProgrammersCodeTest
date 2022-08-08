#include <string>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<>());
    return stoll(s);
}