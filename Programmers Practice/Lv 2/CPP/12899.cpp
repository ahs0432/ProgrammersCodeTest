#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(int n) {
    string answer = "";
    
    while (n != 0) {
        if (n % 3 == 0) {
            answer = "4" + answer;
            n = n / 3 - 1;
            continue;
        }
        
        answer = to_string(n % 3) + answer;
        n /= 3;
    }
    
    return answer;
}