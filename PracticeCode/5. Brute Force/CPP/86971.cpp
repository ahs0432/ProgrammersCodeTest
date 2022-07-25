#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> tmpWires = wires;
    vector<int> wireCount(n, 1);
    vector<int> parents(n, -1);
    queue<int> q;

    q.push(0);

    while (!wires.empty() && !q.empty()) {
        for (int i = 0; i < wires.size(); i++) {
            if (wires[i][0] - 1 == q.front()) {
                q.push(wires[i][1] - 1);
                parents[wires[i][1] - 1] = q.front();
            } else if (wires[i][1] - 1 == q.front()) {
                q.push(wires[i][0] - 1);
                parents[wires[i][0] - 1] = q.front();
            } else {
                continue;
            }

            wireCount[q.front()] += 1;
            wires.erase(wires.begin() + i);
            i--;
        }

        int now = q.front();
        while (true) {
            if (parents[now] != -1) {
                wireCount[parents[now]] += (wireCount[q.front()] - 1);
                now = parents[now];
            } else {
                break;
            }
        }

        q.pop();
    }

    int answer = n;
    for (int wire : wireCount) {
        if (abs((n - wire) - wire) < answer) {
            answer = abs((n - wire) - wire);
        }
    }

    return answer;
}

int main() {
    cout << solution(9, {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}}) << endl;
    cout << solution(4, {{1,2},{2,3},{3,4}}) << endl;
    cout << solution(7, {{1,2},{2,7},{3,7},{3,4},{4,5},{6,7}}) << endl;

    return 0;
}