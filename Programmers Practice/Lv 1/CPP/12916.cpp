#include <string>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
bool solution(string s) {
    int answer = 0;
    
    for (char c : s) {
        if (c == 'P' || c == 'p') {
            answer += 1;
        } else if (c == 'Y' || c == 'y') {
            answer -= 1;
        }
    }
    
    if (answer == 0) {
        return true;
    }
    return false;
}