#include <string>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// isdigit() 함수를 이용하여 다 쉽게 해소 가능
bool solution(string s) {
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    
    for (char c : s) {
        int i = (c - '0');
        if (i < 0 || i > 9) {
            return false;
        }
    }
    
    return true;
}