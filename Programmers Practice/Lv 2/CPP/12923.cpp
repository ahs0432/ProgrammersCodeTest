#include <string>
#include <vector>

using namespace std;

// 효율성 실패
vector<int> solution(long long begin, long long end) {
    vector<int> answer(end, 0);
    
    for (int i = 1; i <= end / 2; i++) {
        for (int j = i * 2; j <= end; j+=i) {
            answer[j - 1] = i;
        }
    }
    
    vector<int> slice;
    slice.assign(answer.begin() + begin - 1, answer.end());
    
    return slice;
}