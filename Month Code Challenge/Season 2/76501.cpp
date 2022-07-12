#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++) {
        if (signs[i]) {
            answer += absolutes[i];
        } else {
            answer -= absolutes[i];
        }
    }
    return answer;
}