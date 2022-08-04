#include <string>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 2로 나눌 때마다 1개씩 추가하여 수박을 추가하고 나머지에 대해 수만 추가하면 더 빠른 처리 가능
string solution(int n) {
    string answer = "";
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            answer += "박";
        } else {
            answer += "수";
        }
    }
    
    return answer;
}