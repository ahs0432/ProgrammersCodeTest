int solution(int n) {
    if (n == 1 && n == 2) {
        return 1; 
    } else if (n == 0) {
        return 0;
    }
    
    int first = 1;
    int second = 1;
    
    for (int i = 2; i < n; i++) {
        int tmp = second;
        second = (first + second) % 1234567;
        first = tmp;
    }
    
    return second;
}