#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[1] < b[1]) {
        return true;
    } else if (a[1] == b[1]) {
        if (a[0] < b[0]) {
            return true;
        } else if (a[0] == b[0]) {
            if (a[2] < b[2]) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    sort(program.begin(), program.end(), compare);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    int nowTime = 0;
    int next = 0;
    
    while (next < program.size() || !pq.empty()) {
        for (; next < program.size() && (program[next][1] <= nowTime || pq.empty()) ; next++) {
            pq.push(program[next]);
        }
        
        vector<int> p = pq.top();
        pq.pop();
        
        if (nowTime > p[1]) {
            answer[p[0]] += (nowTime - p[1]);
        } else if (nowTime < p[1]) {
            nowTime = p[1];
        }
        
        nowTime += p[2];
    }
    answer[0] = nowTime;
    
    return answer;
}