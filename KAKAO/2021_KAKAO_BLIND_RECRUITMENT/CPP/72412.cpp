#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <iostream>

using namespace std;

map<vector<string>, vector<int>> infoMap;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

void infoMapAdd(int num, int infoScore, vector<string> infoText) {
    if (num == 4) {
        return;
    }

    infoText[num] = "-";

    for (int i = num+2; i < 4; i++) {
        infoMapAdd(i, infoScore, infoText);
    }
    
    infoMap[infoText].push_back(infoScore);
    infoMapAdd(num+1, infoScore, infoText);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (string infoText : info) {
        vector<string> infoSplits = split(infoText, ' ');
        int infoScore = atoi(infoSplits[4].c_str());
        infoSplits.pop_back();
        infoMap[infoSplits].push_back(infoScore);
        for (int i = 0; i < 4; i++) {
            infoMapAdd(i, infoScore, infoSplits);
        }
    }

    int queryCount = 0;
    vector<string> querys;

    for (string qText : query) {
        queryCount = 0;
        querys = split(qText, ' ');
        querys.erase(querys.begin() + 1);
        querys.erase(querys.begin() + 2);
        querys.erase(querys.begin() + 3);

        int qScore = atoi(querys[4].c_str());
        querys.pop_back();
        
        for (int infoScore : infoMap[querys]) {
            if (qScore <= infoScore) {
                queryCount++;
            }
        }
        
        answer.push_back(queryCount);
    }
    
    return answer;
}

int main() {
    vector<int> answer = solution(
        vector<string>{
            "java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50"}, 
        vector<string>{
            "java and backend and junior and pizza 100",
            "python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250",
            "- and backend and senior and - 150",
            "- and - and - and chicken 100",
            "- and - and - and - 150"}
        );

    for (int a : answer) {
        cout << a << endl;
    }
}