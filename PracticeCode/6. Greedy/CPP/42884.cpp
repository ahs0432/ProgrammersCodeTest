#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < routes.size(); i++) {
        pq.push({routes[i][1], routes[i][0]});
    }

    int answer = 1;
    int nowNum = pq.top().first;
    pq.pop();

    while(!pq.empty()) {
        int f = pq.top().second;
        int e = pq.top().first;
        pq.pop();

        if (f <= nowNum && e >= nowNum) {
            continue;
        } else {
            nowNum = e;
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(vector<vector<int>>{{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}}) << endl;
    cout << solution(vector<vector<int>>{{-2,-1}, {1,2}, {-3,0}}) << endl; // 2
}