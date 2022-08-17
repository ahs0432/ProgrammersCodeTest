using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// a, b 수를 - 한 뒤 지속 나누기 하여 같아질 때까지 하는 방법도 존재..
int nowRound(int p) {
    if (p % 2 == 0) {
        p /= 2;
    } else {
        p = p / 2 + 1;
    }
    
    return p;
}

int solution(int n, int a, int b) {
    int answer = 1;
    
    while (true) {
        if ((a - 1 == b && a % 2 == 0) || (a + 1 == b && b % 2 == 0)) {
            break;
        }
        
        a = nowRound(a);
        b = nowRound(b);
        answer++;
    }

    return answer;
}