#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> searchDest(string begin, vector<vector<string>> tickets) {
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == begin) {
            pq.push({tickets[i][1], i});
        }
    }
    return pq;
}

vector<string> dfs(int num, int totalTicket, string begin, vector<vector<string>> tickets, vector<string> seqData) {
    if (num != -1) {
        seqData.push_back(begin);
        tickets.erase(tickets.begin() + num);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq = searchDest(begin, tickets);

    while(pq.size() != 0) {
        vector<string> tmpData = dfs(pq.top().second, totalTicket, pq.top().first, tickets, seqData);
        pq.pop();

        if (totalTicket == tmpData.size()) {
            return tmpData;
        }
    }

    if (tickets.size() == 0) {
        return seqData;
    }
    return vector<string>{};
}

vector<string> solution(vector<vector<string>> tickets) {
    return dfs(-1, tickets.size() + 1, "ICN", tickets, vector<string>{"ICN"});
}

int main() {
    /*
    for (string a : solution(vector<vector<string>>{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}})) {
        cout << a << endl;
    }
    */

    for (string a : solution(vector<vector<string>>{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}})) {
        cout << a << endl;
    }

    return 0;
}