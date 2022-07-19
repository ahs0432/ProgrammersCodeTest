#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {
    int open = 0;
    
    for (char c : s) {
        if (c == '(') {
            open += 1;
        } else {
            open -= 1;
            if (open < 0) {
                return false;
            }
        }
    }
    
    // open이 0인지 true false를 return 하면 구문을 줄일 수 있었는데...
    if (open != 0) {
        return false;
    }
    return true;
}