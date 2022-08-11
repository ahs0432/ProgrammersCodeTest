#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// accumulate 함수를 이용하여 더할 수 있음
double solution(vector<int> arr) {
    double total = 0.0;
    for (int i : arr) {
        total += i;
    }
    return total / arr.size();
}