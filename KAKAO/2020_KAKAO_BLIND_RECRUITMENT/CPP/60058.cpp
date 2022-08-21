#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(string p) {
    if (p.size() == 0) {
        return "";
    }
    
    string answer = "";
    
    int num = 0;
    bool startN = true;
    
    for (int i = 0; i < p.size(); i++) {
        num += (p[i] == '(' ? 1 : -1);
        
        if (num == -1) {
            startN = false;
        }
        
        if (i != 0 && num == 0) {
            string p1 = p.substr(0, i + 1);
            if (startN) {
                answer += p1 + solution(p.substr(i + 1, p.size() - 1 - i));
            } else {
                string tmp = p1.substr(1, p1.size() - 2);
                for (int i = 0; i < tmp.size(); i++) {
                    if (tmp[i] == '(') {
                        tmp[i] = ')';
                    } else {
                        tmp[i] = '(';
                    }
                }
                answer += "(" + solution(p.substr(i + 1, p.size() - 1 - i)) + ")";
                answer += tmp;
            }
            
            break;
        }
    }
    
    return answer;
}