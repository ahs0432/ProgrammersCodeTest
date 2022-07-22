#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> node;

void dfs(vector<vector<int>> computers, int nowIndex) {
    vector<int> computer = computers[nowIndex];

    for (int i = 0; i < computer.size(); i++) {
        if (i != nowIndex && computer[i] == 1 && !node[i]) {
            node[i] = true;
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    node = vector<bool>(n);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (node[i]) {
            continue;
        }
        answer++;
        node[i] = true;
        dfs(computers, i);
    }
    
    return answer;
}

int main() {
    cout << solution(3, vector<vector<int>>{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
    cout << solution(3, vector<vector<int>>{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;
}