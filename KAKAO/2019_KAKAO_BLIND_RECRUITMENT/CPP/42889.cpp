#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
struct cmp{
    bool operator()(pair<float, int>&a, pair<float, int>&b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> noClear(N+1);
    priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> faultRate;
    vector<int> answer;
    
    for (int stage : stages) {
        noClear[stage-1] += 1;
    }
    
    int totalCount = noClear[N];
    for (int i = (N-1); i >= 0; i--) {
        totalCount += noClear[i];
        if (totalCount != 0 && noClear[i] == totalCount) {
            faultRate.push({1.0, i});
        } else if (noClear[i] != 0 && totalCount != 0) {
            faultRate.push({float(noClear[i]) / float(totalCount), i});
        } else {
            faultRate.push({0.0, i});
        }
    }

    for (int i = 0; i < N; i++) {
        answer.push_back((faultRate.top().second + 1));
        faultRate.pop();
    }
    
    return answer;
}

int main() {
    for (int a : solution(5, {2, 1, 2, 6, 2, 4, 3, 3})) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(4, {4,4,4,4,4})) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}