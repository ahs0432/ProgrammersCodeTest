#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int sc : scoville) {
        pq.push(sc);
    }

    int answer = 0;

    while (pq.top() < K) {
        if (pq.size() == 1) {
            return -1;
        }

        answer++;
        
        int min = pq.top();
        pq.pop();
        pq.push(min + (pq.top() * 2));
        pq.pop();
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{1, 2, 3, 9, 10, 12}, 7) << endl;
}