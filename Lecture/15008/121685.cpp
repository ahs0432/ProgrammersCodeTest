#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    vector<string> lists = {"RR", "Rr", "Rr", "rr"};
    
    for (vector<int> q : queries) {
        if (q[0] == 1) {
            answer.push_back("Rr");
            continue;
        }
        
        vector<int> locations(q[0], 0);
        locations[q[0] - 1] = q[1] - 1;
        
        for (int i = q[0] - 2; i >= 1; i--) {
            locations[i] = q[1] / 4;
            q[1] = q[1] / 4;
        }
        
        string now = "Rr";
        for (int i = 1; i < locations.size(); i++) {
            if (now == "RR") {
                break;
            } else if (now == "rr") {
                break;
            } else {
                now = lists[locations[i] % 4];
            }
        }
        
        answer.push_back(now);
    }
    
    return answer;
}