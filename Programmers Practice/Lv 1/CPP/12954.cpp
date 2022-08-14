#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for (int i = 1; i <= n; i++) {
        answer.push_back(x * i);
    }
    
    return answer;
}