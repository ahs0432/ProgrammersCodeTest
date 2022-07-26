#include <string>
#include <vector>
#include <queue>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 아예 sort 에서 구분하는 방식으로도 해결 가능
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    priority_queue<pair<char, string>,vector<pair<char, string>>, greater<pair<char, string>>> pq;
    
    for (string s : strings) {
        pq.push({s[n], s}); 
    }
    
    while(pq.size() != 0) {
        answer.push_back(pq.top().second);
        pq.pop();
    }
    
    return answer;
}