#include <string>
#include <cmath>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
long long solution(long long n) {
    long long sq = sqrt(n);
    // 하나는 pow 써놓고...
    return ((sq * sq == n) ? pow(sq + 1, 2) : -1);
}

