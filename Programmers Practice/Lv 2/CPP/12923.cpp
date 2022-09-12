#include <string>
#include <vector>

using namespace std;

// 효율성 실패 3
vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        
        bool check = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                answer.push_back(i / j);
                check = true;
                break;
            }
        }
        
        if (!check) {
            answer.push_back(1);
        }
    }
    
    return answer;
}