#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(string s, int n) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        } else {
            if (s[i] <= 90 && (s[i] + n) > 90) {
                s[i] += (n - 26);
            } else if ((s[i] + n) > 122) {
                s[i] += (n - 26);
            } else {
                s[i] += n;
            }
        }
    }
    
    return s;
}