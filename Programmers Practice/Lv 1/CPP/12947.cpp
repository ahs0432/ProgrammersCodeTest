#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
bool solution(int x) {
    int xTotal = 0;
    int tmpX = x;
    
    while (tmpX != 0) {
        xTotal += (tmpX % 10);
        tmpX /= 10;
    }
    
    return (x % xTotal) ? false : true;
}