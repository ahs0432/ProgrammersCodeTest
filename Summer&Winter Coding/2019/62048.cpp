using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int gcdCalc(int a, int b) {
    if (a > b) {
        int tmpA = a;
        a = b;
        b = tmpA;
    }
    
    while (b != 0) {
        int n = a % b;
        a = b;
        b = n;
    }
    
    return a;
}

long long solution(int w, int h) {
    return ((long long)w * h) - (h + w - gcdCalc(h, w));
}