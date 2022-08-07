#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// toupper tolower를 이용하는 방식도 존재
string solution(string s) {
    int c = 2;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            c = 2;
            continue;
        }
        
        if (c % 2 == 0) {
            if (s[i] >= 97) {
                s[i] -= 32;
            }
        } else {
            if (s[i] <= 90) {
                s[i] += 32;
            }
        }
        c++;
    }
    
    return s;
}