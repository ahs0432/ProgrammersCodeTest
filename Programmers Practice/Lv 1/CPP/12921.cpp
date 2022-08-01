#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    int answer = 0;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            answer += 1;
            
            for (int j = (i * 2); j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    
    
    return answer;
}