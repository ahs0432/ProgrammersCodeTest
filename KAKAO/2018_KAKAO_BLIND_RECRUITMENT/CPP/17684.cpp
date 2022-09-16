#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    int lastNum = 27;
    map<string, int> words;
    
    for (int i = 1; i < 27; i++) {
        string tmpString(1, char(64 + i));
        words[tmpString] = i;
    }
    
    bool keep = false;
    for (int i = 0; i < msg.size(); i++) {
        int nowNum = words[msg.substr(i, 1)];
        int lastPlus = 0;
        
        for (int j = 0; j < msg.size() - i; j++) {
            if (words[msg.substr(i, j + 2)] != 0) {
                lastPlus += 1;
                nowNum = words[msg.substr(i, j + 2)];
            } else {
                words[msg.substr(i, j + 2)] = lastNum++;
                break;
            }
        }
        
        answer.push_back(nowNum);
        i += lastPlus;
    }
    
    return answer;
}