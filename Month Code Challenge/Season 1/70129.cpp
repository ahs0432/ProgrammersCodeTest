#include <string>
#include <vector>

using namespace std;

string toBinary(int i) {
    string b = "";
    
    while (i != 0) {
        b = to_string(i % 2) + b;
        i /= 2;
    }
    
    return b;
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    string tmp = "";
    
    while (s.size() != 1) {
        answer[0] += 1;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                answer[1]++;
            } else {
                tmp += "1";
            }
        }
        
        s = toBinary(tmp.size());
        tmp = "";
    }
    
    return answer;
}