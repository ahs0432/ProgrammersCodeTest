#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(string s) {
    if (s.size() == 1) {
        return 1;
    }
    
    int answer = s.size() * 2;
    
    for (int i = 1; i <= s.size()/2; i++) {
        string ss = "";
        string lastS = "";
        int lastN = 0;
        
        for (int j = 0; j < s.size(); j+=i) {
            if (lastS == "") {
                lastS = s.substr(j, i);
                lastN = 1;
            } else {
                if (lastS == s.substr(j, i)) {
                    lastN++;
                    continue;
                }
                
                if (lastN != 1) {
                    ss += to_string(lastN);
                    lastN = 1;
                }
                ss += lastS;
                lastS = s.substr(j, i);
            }
        }
        
        if (lastN != 1) {
            ss += to_string(lastN);
        }
        ss += lastS;
        
        if (answer > ss.size()) {
            answer = ss.size();
        }
    }
    
    return answer;
}