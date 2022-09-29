#include <string>
#include <vector>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer = {0, 0};
    
    int type = 0;
    
    for (char c : command) {
        if (c == 'R') {
            type += 1;
            
            if (type == 4) {
                type = 0;
            }
        } else if (c == 'L') {
            type -= 1;
            
            if (type == -1) {
                type = 3;
            }
        } else if (c == 'G') {
            if (type == 0) {
                answer[1] += 1;
            } else if (type == 1) {
                answer[0] += 1;
            } else if (type == 2) {
                answer[1] -= 1;
            } else {
                answer[0] -= 1;
            }
        } else {
            if (type == 0) {
                answer[1] -= 1;
            } else if (type == 1) {
                answer[0] -= 1;
            } else if (type == 2) {
                answer[1] += 1;
            } else {
                answer[0] += 1;
            }
        }
    }
    
    
    return answer;
}