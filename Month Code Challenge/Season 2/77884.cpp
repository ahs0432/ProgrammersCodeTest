#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++) {
        int tmpCount = 1;
        if (i > 1) {
            tmpCount += 1;
        }
        
        for (int j = 2; j <= (i / 2); j++) {
            if (i % j == 0) {
                tmpCount++;
            }
        }
        
        if (tmpCount % 2 == 0) {
            answer += i;
        } else {
            answer -= i;
        }
    }
    
    return answer;
}