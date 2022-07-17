#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int n) {
    int answer = 0;
    string ternary = "";
    while (n >= 3) {
        ternary = to_string(n%3) + ternary;
        n = n / 3;
    }
    ternary = to_string(n) + ternary;
    
    int digit = 1;
    for (char c : ternary) {
        int a = (c - '0');
        answer += (a * digit);
        if (digit == 1) {
            digit = 3;
        } else {
            digit *= 3;
        }
    }
    
    return answer;
}