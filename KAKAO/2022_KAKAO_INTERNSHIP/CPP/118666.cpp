#include <string>
#include <vector>
#include <map>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> sInt;
    
    for (int i = 0; i < survey.size(); i++) {
        int c = choices[i] - 4;
        
        if (c < 0) {
            sInt[survey[i][0]] += abs(c);
        } else {
            sInt[survey[i][1]] += c;
        }
    }
    
    answer += (sInt['R'] >= sInt['T'] ? "R" : "T");
    answer += (sInt['C'] >= sInt['F'] ? "C" : "F");
    answer += (sInt['J'] >= sInt['M'] ? "J" : "M");
    answer += (sInt['A'] >= sInt['N'] ? "A" : "N");
    
    return answer;
}