#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int a : ability) {
        pq.push(a);
    }
    
    for (int i = 0; i < number; i++) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        for (int j = 0; j < 2; j++) {
            pq.push(a + b);
        }
    }
    
    int answer = 0;
    while(!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    
    return answer;
}