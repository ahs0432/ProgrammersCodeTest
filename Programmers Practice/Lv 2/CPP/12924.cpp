int solution(int n) {
    if (n < 3) {
        return 1;
    }
    
    int answer = 1;
    
    for (int i = 1; i <= (n / 2) + (n % 2); i++) {
        int now = i;
        
        for (int j = (i + 1); now < (n + 1); j++) {
            if (now == n) {
                answer++;
            }
            now += j;
        }
    }
    
    return answer;
}