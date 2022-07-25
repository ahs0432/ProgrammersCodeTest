#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 비트 연산자를 통한 더 짧고 빠른 코드 작성 가능
long long solution(int a, int b) {
    long long answer = 0;
    
    if (b < a) {
        int tmpA = a;
        a = b;
        b = tmpA;
    } else if (a == b) {
        return a;
    }
    
    long long total = abs(b - a) + 1;
    long long sum = (a + b);
    
    if (total % 2 == 0) {
        return sum * (total / 2);
    } else {
        return sum * (total / 2) + (sum / 2);
    }
}