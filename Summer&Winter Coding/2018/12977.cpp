#include <vector>
using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<bool> prime(3000, true);

void inPrime() {
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i < prime.size(); i++) {
        if(!prime[i]) {
            continue;
        }
        
        for (int j = (i * 2); j < prime.size(); (j+=i)) {
            prime[j] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    inPrime();
    
    for(int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] != nums[k] && nums[j] != nums[k] && prime[nums[i] + nums[j] + nums[k]]) {
                        answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}