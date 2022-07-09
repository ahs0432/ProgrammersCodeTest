#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 2147483647

using namespace std;

vector<int> dijkstra(int n, int s, vector<pair<int, int>> loc[]) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < loc[cur].size(); i++) {
            int next = loc[cur][i].first;
            int nCost = cost + loc[cur][i].second;
            if (nCost < dist[next] ) {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }

    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<pair<int, int>> loc[n];

    for (vector<int> fare : fares) {
        loc[fare[0]-1].push_back(make_pair(fare[1]-1, fare[2]));
        loc[fare[1]-1].push_back(make_pair(fare[0]-1, fare[2]));
    }

    vector<int> dist = dijkstra(n, s-1, loc);
    int answer = dist[a-1] + dist[b-1];

    for (int i = 0; i < n; i++) {
        if (s-1 != i) {
            vector<int> tmpDist = dijkstra(n, i, loc);
            if (dist[i] + tmpDist[a-1] + tmpDist[b-1] < answer) {
                answer = dist[i] + tmpDist[a-1] + tmpDist[b-1];
            }
        }
    }

    return answer;
}

int main() {
    cout << solution(6, 4, 6, 2, vector<vector<int>>{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    cout << solution(7, 3, 4, 1, vector<vector<int>>{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    cout << solution(6, 4, 5, 6, vector<vector<int>>{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}}) << endl;
    
    return 0;
}