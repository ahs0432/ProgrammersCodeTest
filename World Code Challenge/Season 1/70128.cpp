#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++) {
        answer += (a[i] * b[i]);
    }
    return answer;
}