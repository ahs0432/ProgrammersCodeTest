#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long qTotal = 0;
    long total = 0;
    
    int max = 0;
    queue<int> q1;
    queue<int> q2;
    
    for (int i : queue1) {
        if (max < i) {
            max = i;   
        }
        q1.push(i);
        qTotal += i;
        total += i;
    }
    
    for (int i : queue2) {
        if (max < i) {
            max = i;   
        }
        q2.push(i);
        total += i;
    }
    
    if (max > (total / 2) || (total % 2) != 0) {
        return -1;
    }
    
    int answer = 0;
    int qSize = queue1.size() + queue2.size() + 1;
    long endPoint = (total / 2);
    
    while (qTotal != endPoint) {
        if (answer > qSize) {
            return -1;
        }
        
        if (qTotal < endPoint) {
            qTotal += q2.front();
            q1.push(q2.front());
            q2.pop();
        } else {
            qTotal -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        answer++;
    }
    
    return answer;
}