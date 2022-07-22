using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
long long solution(int price, int money, int count) {
    long long answer = 0;
    
    for (int i = 1; i <= count; i++) {
        answer += (price * i);
    }
    
    if ((answer - money) <= 0) {
        return 0;
    }
    
    return (answer - money);
}