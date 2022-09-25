#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string input_string) {
    string answer = "";
    
    char lastAlpha = 'A';
    map<char, int> alpha;
    
    for (char c : input_string) {
        if (lastAlpha == c) {
            continue;
        }
        alpha[c]++;
        lastAlpha = c;
    }
    
    for(auto iter = alpha.begin() ; iter !=  alpha.end(); iter++) {
        if (iter->second > 1) {
            answer.push_back(iter->first);
        }
    }
    
    if (answer == "") {
        return "N";
    }
    return answer;
}