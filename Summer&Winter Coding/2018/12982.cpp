#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    for (int m : d) {
        if (budget < m) {
            break;
        }
        budget -= m;
        answer++;
    }
    
    return answer;
}