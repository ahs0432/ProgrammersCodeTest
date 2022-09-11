#include <string>
#include <vector>

using namespace std;

// 효율성 실패 2
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    vector<bool> isPrime(end + 1, true);
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(long long i = 2; i * i <= end; i++){
        if(isPrime[i]){
            for(long long j = i * i; j <= end; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        
        if (isPrime[i]) {
            answer.push_back(1);
        } else {
            for (long long j = 2; j <= i/2; j++) {
                if (i % j == 0) {
                    answer.push_back(i / j);
                    break;
                }
            }
        }
    }
    
    return answer;
}