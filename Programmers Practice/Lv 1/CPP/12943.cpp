using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// int 값이 초과되는 현상으로 인해 long long으로 변환
int solution(int n) {
    long long num = n;
    int answer = 0;
    
    while (answer <= 500) {
        if (num == 1) return answer;
        
        num = (num % 2) ? (num * 3 + 1) : (num / 2);
        answer++;
    }
    
    return -1;
}