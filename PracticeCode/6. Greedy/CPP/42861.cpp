#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
#define INF 2147483647

// 열심히 연구해서 만들어본 코드.. 나중에 분석해서 작성해보자
int primAl(int n, vector<pair<int, int>> loc[]) {
    vector<int> dist(n, INF);
    vector<bool> visit(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0});

    int total = 0;

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (visit[curNode]) {
            continue;
        }
        visit[curNode] = true;
        total += curCost;

        for (int i = 0; i < loc[curNode].size(); i++) {
            int nextLoc = loc[curNode][i].first;
            int nextCost = loc[curNode][i].second;

            if (!visit[nextLoc]) {
                pq.push({nextCost, nextLoc});
            }
        }
    }

    return total;
}

// 프림 알고리즘을 이용할 것 / 크루스칼 알고리즘 확인도 필요 (동일한 역할을 하나 상황에 따라 성능 차이가 발생)
int solution(int n, vector<vector<int>> costs) {
    vector<pair<int, int>> costMap[n];

    for (int i = 0; i < costs.size(); i++) {
        costMap[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        costMap[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    int answer = primAl(n, costMap);
    return answer;
}

int main() {
    cout << solution(4, vector<vector<int>>{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}) << endl;
}