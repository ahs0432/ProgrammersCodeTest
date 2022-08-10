#include <string>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 비트 연산으로 마지막 비트의 수가 0인지 1인지로 구분 가능
string solution(int num) {
    return (num % 2) ? "Odd" : "Even";
}