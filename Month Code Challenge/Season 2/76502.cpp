#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(string s) {
    int answer = 0;
    
    if (s.size() % 2 != 0) {
        return 0;
    }
    
    queue<char> sq;
    
    stack<char> lastOpen;
    bool checkTrue = true;
    int bracket = 0; // []
    int brace = 0; // {}
    int parenthesis = 0; // ()
    
    for (char c : s) {
        sq.push(c);
        if (c == '[') {
            lastOpen.push(c);
            bracket++;
        } else if (c == ']') {
            bracket--;
            if (bracket < 0 || lastOpen.empty() || lastOpen.top() != '[') { 
                checkTrue = false;
                continue;
            }
            lastOpen.pop();
        } else if (c == '{') {
            lastOpen.push(c);
            brace++;
        } else if (c == '}') {
            brace--;
            if (brace < 0 || lastOpen.empty() || lastOpen.top() != '{') { 
                checkTrue = false;
                continue;
            }
            lastOpen.pop();
        } else if (c == '(') {
            lastOpen.push(c);
            parenthesis++;
        } else {
            parenthesis--;
            if (parenthesis < 0 || lastOpen.empty() || lastOpen.top() != '(') { 
                checkTrue = false;
                continue;
            }
            lastOpen.pop();
        }
    }
    
    if (checkTrue) {
        answer++;
    }
    
    if (bracket % 2 != 0 || brace % 2 != 0 || parenthesis % 2 != 0) {
        return 0;
    }
    
    for (int i = 0; i < s.size() - 1; i++) {
        lastOpen = stack<char>();
        checkTrue = true;
        bracket = 0;
        brace = 0;
        parenthesis = 0;
        
        sq.push(sq.front());
        sq.pop();
        
        for (int j = 0; j < s.size(); j++) {
            char c = sq.front();
            sq.push(sq.front());
            sq.pop();
            
            if (checkTrue) {
                if (c == '[') {
                    lastOpen.push(c);
                    bracket++;
                } else if (c == ']') {
                    bracket--;
                    if (bracket < 0 || lastOpen.empty() || lastOpen.top() != '[') { 
                        checkTrue = false;
                        continue;
                    }
                    lastOpen.pop();
                } else if (c == '{') {
                    lastOpen.push(c);
                    brace++;
                } else if (c == '}') {
                    brace--;
                    if (brace < 0 || lastOpen.empty() || lastOpen.top() != '{') { 
                        checkTrue = false;
                        continue;
                    }
                    lastOpen.pop();
                } else if (c == '(') {
                    lastOpen.push(c);
                    parenthesis++;
                } else {
                    parenthesis--;
                    if (parenthesis < 0 || lastOpen.empty() || lastOpen.top() != '(') { 
                        checkTrue = false;
                        continue;
                    }
                    lastOpen.pop();
                }
            }
        }
        
        if (checkTrue) {
            answer++;
        }
    }
    
    return answer;
}