#include <string>

using namespace std;

// toupper와 tolower 이용하면 더 쉽게 끝날 수 있음..
string solution(string s) {
    bool blank = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            blank = false;
            continue;
        } else if (s[i] == ' ') {
            blank = true;
        } else {
            if (blank) {
                blank = false;
                
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] -= 32;
                }
            } else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] += 32;
                }
            }
        }
    }
    
    return s;
}