long long solution(int n) {
    if (n == 0) {
        return 1;
    }
    
    long long total = 0;
    total += solution(n - 1);
    if (n >= 2) total += solution(n - 2);
    
    return total % 1234567;
}