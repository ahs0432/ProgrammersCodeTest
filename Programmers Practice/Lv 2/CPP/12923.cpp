#include <string>
#include <vector>

using namespace std;

// 지문 상 10,000,000번 까지 블록을 놓는다는 내용을 참고해야함...
vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        
        bool check = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0 && i / j <= 10000000) {
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