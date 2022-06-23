#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> totalScore;
    map<string, vector<int>> genList;

    for (int i = 0; i < genres.size(); i++) {
        totalScore[genres[i]] += plays[i];
        if (genList[genres[i]].empty()) {
            genList[genres[i]].push_back(i);
        } else if (genList[genres[i]].size() == 1) {
            if (plays[genList[genres[i]][0]] < plays[i]) {
                genList[genres[i]].push_back(genList[genres[i]][0]);
                genList[genres[i]][0] = i;
            } else {
                genList[genres[i]].push_back(i);
            }
        } else {
            if (plays[genList[genres[i]][0]] < plays[i]) {
                genList[genres[i]][1] = genList[genres[i]][0];
                genList[genres[i]][0] = i;
            } else if (plays[genList[genres[i]][1]] < plays[i]) {
                genList[genres[i]][1] = i;
            }
        }
    }

    vector<int> totalSort;
    for (map<string, int>::iterator iter = totalScore.begin(); iter != totalScore.end(); iter++) {
        totalSort.push_back(iter->second);
    }

    sort(totalSort.begin(), totalSort.end());
    reverse(totalSort.begin(), totalSort.end());

    vector<int> answer;

    for (int ts : totalSort) {
        for (map<string, int>::iterator iter = totalScore.begin(); iter != totalScore.end(); iter++) {
            if (iter->second == ts) {
                answer.insert(answer.end(), genList[iter->first].begin(), genList[iter->first].end());
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> a = solution(vector<string>{"classic", "pop", "classic", "classic", "pop"}, vector<int>{500, 600, 150, 800, 2500});
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}