#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 나는 특정 규칙을 이용하여 풀었지만 이외에도 그냥 while로 무작정 비교하는 방식도 존재함
// 이때 비트셋을 이용하면 빠른 속도로 비트에 수를 하나씩 추가하여 처리하는 것이 가능함.

string toBinary(int n) {
    string b = "";
    
    while (n != 0) {
        b = to_string(n % 2) + b;
        n /= 2;
    }
    
    return b;
}

int toInteger(string b) {
    int n = 0;
    int now = 1;
    
    while (!b.empty()) {
        if (b.back() == '1') {
            n += (now);
        }
        
        now *= 2;
        b.pop_back();
    }
    
    return n;
}

int solution(int n) {
    if (n == 0) {
        return 0;
    }
    
    string b = toBinary(n);
    
    int oneCount = 0;
    int lastNumber = 0;
    
    reverse(b.begin(), b.end());
    b.push_back('0');
    
    // 0과 가장 근접한 1을 Exchange하고 그 뒤에 숫자를 이용하여 1이 뒷쪽에 위치하도록 함
    // 예: 1001110 -> 1010110(1 Step) -> 1010011 (2 Step) ..
    for (int i = 0; i < b.size() - 1; i++) {
        if (b[i] == '1' && b[i + 1] == '0') {
            lastNumber = i;
            b[i] = '0';
            b[i + 1] = '1';
            break;
        } else if (b[i] == '1') {
            oneCount++;
        }
    }
    
    for (int i = 0; i < lastNumber; i++) {
        if (oneCount > 0) {
            oneCount--;
            b[i] = '1';
        } else {
            b[i] = '0';
        }
    }
    
    reverse(b.begin(), b.end());
    
    return toInteger(b);
}