#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 10진수 -> 2진수 변환
string toBinary(int n) {
    string b = "";
    
    while (n != 0) {
        b = to_string(n % 2) + b;
        n /= 2;
    }
    
    return b;
}

// 2진수 -> 10진수 변환
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

// 정확성 2, 4번 실패.. 원인이 뭐지..
int solution(int n) {
    if (n == 0) {
        return 0;
    }
    
    string b = toBinary(n);
    
    int oneCount = 0;
    int zeroCount = 0;
    
    bool conCheck = true;
    int lastNum = 0;
    
    // 0과 가장 근접한 1을 Exchange하고 그 뒤에 숫자를 이용하여 1이 뒷쪽에 위치하도록 함
    // 예: 1001110 -> 1010110(1 Step) -> 1010011 (2 Step) ..
    for (int i = b.size() - 1; i >= 0; i--) {
        if (conCheck && i != 0 && b[i] == '0' && b[i + 1] == '1') {
            conCheck = false;
            b[i] = '1';
            b[i + 1] = '0';
            lastNum = i;
            oneCount--;
        }
        
        if (b[i] == '0') {
            zeroCount++;
        } else if (conCheck) {
            oneCount++;
        }
    }
    
    if (zeroCount == 0) {
        b[0] = '0';
        b = "1" + b;
    } else {
        if (conCheck) {
            b[0] = '0';
            b = "1" + b;
            oneCount--;
            lastNum = 1;
        }
        
        if (oneCount >= 0) {
            for (int i = b.size() - 1; i > lastNum; i--) {
                if (oneCount != 0) {
                    b[i] = '1';
                    oneCount--;
                } else {
                    b[i] = '0';
                }
            }
        } 
    }
    
    return toInteger(b);
}