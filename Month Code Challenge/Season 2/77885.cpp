#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제

// long long -> Binary(string)
string toBinary(long long num) {
    string bit = "";
    
    while (num >= 2) {
        bit = to_string(num % 2) + bit;
        num /= 2;
    }
    bit = "0" + to_string(num) + bit;
    
    return bit;
}

// Binary(string) -> long long
long long toLongLong(string binary) {
    long long num = 0;
    long long nowNum = 1;
    
    for (int i = binary.size() - 1; i >= 0; i--) {
        num += ((binary[i] == '1') * nowNum);
        nowNum *= 2;
    }
    
    return num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long num : numbers) {
        if (num % 2 == 0) {
            answer.push_back(num + 1);
        } else {
            string binary = toBinary(num);
            bool biOn = false;
            
            for (int i = binary.size() - 1; i >= 0; i--) {
                if (binary[i] == '1') {
                    biOn = true;
                } else {
                    if (biOn) {
                        binary[i] = '1';
                        binary[i + 1] = '0';
                        
                        break;
                    }
                    biOn = false;
                }
            }
            
            answer.push_back(toLongLong(binary));
        }
    }
    
    return answer;
}