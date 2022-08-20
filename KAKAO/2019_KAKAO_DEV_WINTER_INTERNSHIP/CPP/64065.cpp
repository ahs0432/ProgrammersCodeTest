#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> tuples;
    int num = 0;
    bool nowBracket = false;
    
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] == '{') {
            nowBracket = true;
        } else if (s[i] == '}') {
            tuples[num] = tuples[num] + 1;
            num = 0;
            nowBracket = false;
        } else if (s[i] == ',') {
            if (!nowBracket) {
                continue;
            }
            tuples[num] = tuples[num] + 1;
            num = 0;
        } else {
            num *= 10;
            num += s[i] - 48;
        }
    }
    
    priority_queue<pair<int, int>> pq;
    
    auto iter = tuples.begin();
    while (iter != tuples.end()) {
        pq.push({iter->second, iter->first});
        iter++;
    }
    
    while (!pq.empty()) {
        answer.push_back(pq.top().second);
        pq.pop();
    }
    
    return answer;
}