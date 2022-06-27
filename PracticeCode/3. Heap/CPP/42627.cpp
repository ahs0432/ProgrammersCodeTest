#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

// 정확성 85% / TC 7, 10, 18 Timeout 
struct compareDefault {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first>b.first;
	}
};

struct compareProcess {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second>b.second;
	}
};

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareDefault> job_pq;

    for (int i = 0; i < jobs.size(); i++) {
        job_pq.push({jobs[i][0], jobs[i][1]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compareProcess> queuing;

    int nowTime = 0;
    int answer = 0;

    for (int i = 0; i < jobs.size(); i++) {
        if (queuing.empty() && job_pq.top().first > nowTime) {
            nowTime = job_pq.top().first;
        }

        while (true) {
            if (!job_pq.empty() && job_pq.top().first <= nowTime) {
                queuing.push(job_pq.top());
                job_pq.pop();
            } else {
                break;
            }
        }

        nowTime += queuing.top().second;
        answer += (nowTime - queuing.top().first);
        queuing.pop();
    }

    return answer / jobs.size();
}

int main() {
    cout << solution(vector<vector<int>>{{0, 3}, {1, 9}, {2, 6}}) << endl;
    cout << solution(vector<vector<int>>{{1, 3}, {1, 9}, {2, 6}}) << endl;
    cout << solution(vector<vector<int>>{{0, 9}, {1, 1}, {1, 1}, {1, 1}, {1, 1}}) << endl;
    cout << solution(vector<vector<int>>{{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1}}) << endl;
    
}