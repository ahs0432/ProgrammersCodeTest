#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int n) {
    int answer = 0;
    vector<bool> numBool(n, false);
    
    for (int i = 2; i < n; i++) {
        if (numBool[i]) {
            continue;
        }
        
        if (n % i == 1) {
            return i;
        } else {
            for (int j = 1; (i * j) < n; j++) {
                numBool[i * j] = true;
            }
        }
    }
    
    return answer;
}