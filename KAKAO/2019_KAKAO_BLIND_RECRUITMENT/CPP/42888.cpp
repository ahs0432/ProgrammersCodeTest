#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
    
    while (getline(ss, tmp, delimiter)) {
        result.push_back(tmp);
    }
    
    return result;
}

vector<string> solution(vector<string> record) {
    map<string, string> uuid;
    vector<pair<bool, string>> inout;
    
    for (string r : record) {
        vector<string> ssplit = split(r, ' ');
        
        if (ssplit[0] == "Enter") {
            uuid[ssplit[1]] = ssplit[2];
            inout.push_back({true, ssplit[1]});
        } else if (ssplit[0] == "Change") {
            uuid[ssplit[1]] = ssplit[2];
        } else {
            inout.push_back({false, ssplit[1]});
        }
    }
    
    vector<string> answer;
    
    for (pair<bool, string> io : inout) {
        if (io.first) {
            answer.push_back(uuid[io.second] + "님이 들어왔습니다.");
        } else {
            answer.push_back(uuid[io.second] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}