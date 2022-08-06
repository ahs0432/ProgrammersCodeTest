#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int n) {
    if (n < 2) {
        return n;
    }
    
    int answer = 1 + n;
    
    for (int i = 2; i <= (n / 2); i++) {
        if (n % i == 0) {
            answer += i;
        }
    }
    
    return answer;
}