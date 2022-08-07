using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(int n) {
    int answer = 0;
    
    while (n != 0) {
        answer += (n % 10);
        n /= 10;
    }

    return answer;
}