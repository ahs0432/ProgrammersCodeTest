#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int tmp = 0;
    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    
    return a;
}

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        int nowGCD = gcd(answer, arr[i]);
        if (arr[i] % answer == 0) {
            answer = arr[i];
        } else if (answer % arr[i] != 0) {
            answer *= arr[i];
            answer /= nowGCD;
        }
    }
      
    return answer;
}