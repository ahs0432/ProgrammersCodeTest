#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

// 다익스트라 사용 예정
int solution(int N, vector<vector<int>> roads, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> roadQ(N, vector<pair<int, int>>());
    queue<pair<int, int>> pq;
    vector<int> moveCount(N, INF);
    moveCount[0] = 0;
    
    for (vector<int> road : roads) {
        roadQ[road[0] - 1].push_back({road[1] - 1, road[2]});
        roadQ[road[1] - 1].push_back({road[0] - 1, road[2]});
    }
    
    pq.push({0, 0});
    
    while(!pq.empty()) {
        int nowLoc = pq.front().first;
        int nowCount = pq.front().second;
        
        for (pair<int, int> road : roadQ[nowLoc]) {
            int nextLoc = road.first;
            int nextCount = nowCount + road.second;
            
            if (nextCount < moveCount[nextLoc]) {
                moveCount[nextLoc] = nextCount;
                pq.push({nextLoc, nextCount});
            }
        }
        
        pq.pop();
    }
    
    for (int i : moveCount) {
        answer += (i <= K);
    }
    
    return answer;
}