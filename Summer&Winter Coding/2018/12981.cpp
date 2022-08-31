#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    map<string, bool> wordUsed;
    wordUsed[words[0]] = true;
    
    for (int i = 1; i < words.size(); i++) {
        if (wordUsed[words[i]]) {
            answer = {(i % n) + 1, (i / n) + 1}; 
            break;
        } else if (words[i - 1].back() != words[i][0]) {
            answer = {(i % n) + 1, (i / n) + 1};
            break;
        }
        
        wordUsed[words[i]] = true;
    }
    
    return answer;
}