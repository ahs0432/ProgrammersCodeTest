#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

// 정확성 85% / TC 7, 10, 18 Timeout 
struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};

int solution(vector<vector<int>> jobs) {
    int lastSec = 0;
    map<int, vector<int>> jobSec;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (int i = 0; i < jobs.size(); i++) {
        jobSec[jobs[i][0]].push_back(i);
        if (lastSec < jobs[i][0]) {
            lastSec = jobs[i][0];
        }
    }

    int answer = 0;
    int totalSec = 0;
    int remainSec = 0;
    pair<int, int> nowJob;
    bool process = false;

    while(true) {
        if (lastSec < totalSec && !process && pq.empty()) {
            break;
        } 
        if (!jobSec[totalSec].empty()) {
            for (int i = 0; i < jobSec[totalSec].size(); i++) {
                pq.push({jobs[jobSec[totalSec][i]][0], jobs[jobSec[totalSec][i]][1]});
            }
        }

        if (process) {
            remainSec--;
            if (remainSec == 0) {
                process = false;
                answer += ((totalSec+1) - nowJob.first);
            }
        } else {
            if (!pq.empty()) {
                nowJob = pq.top();
                process = true;
                remainSec = nowJob.second - 1;
                pq.pop();
            }
        }
        totalSec++;
    }
    
    return answer / jobs.size();
}

int main() {
    cout << solution(vector<vector<int>>{{0, 3}, {1, 9}, {2, 6}}) << endl;
}