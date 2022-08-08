#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(long long n) {
    vector<int> answer;
    
    while (n != 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}