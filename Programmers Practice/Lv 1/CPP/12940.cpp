#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(int n, int m) {
    if (n > m) {
        int tmp = m;
        int m = n;
        int n = tmp;
    }
    
    vector<int> answer = {0, 0};
    
    if (m % n == 0) {
        answer[0] = n;
    } else {
        for (int i = (n / 2); i > 0; i--) {
            if (n % i == 0 && m % i == 0) {
                answer[0] = i;
                break;
            }
        }
    }
    
    int tmpM = m;
    
    while (true) {
        if (tmpM % n == 0) {
            answer[1] = tmpM;
            break;
        } else {
            tmpM += m;
        }
    }
    
    return answer;
}