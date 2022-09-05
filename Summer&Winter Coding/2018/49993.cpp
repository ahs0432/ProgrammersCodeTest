#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<string> skills;
    
    for (string s : skill_trees) {
        skills.push_back("");
        
        for (int i = 0; i < s.size(); i++) {
            for (char c : skill) {
                if (s[i] == c) {
                    skills.back().push_back(c);
                    break;
                }
            }
        }
    }
    
    int answer = 0;
    
    for (string s : skills) {
        if (s == skill.substr(0, s.size())) {
            answer++;
        }
    }
    
    return answer;
}