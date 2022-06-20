#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// ** 정렬 후 비교 방법도 존재하니 확인해볼 것
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> partic;

    for (string name : participant) {
        partic[name] += 1;
    }

    for (string name : completion) {
        partic[name] -= 1;
        if (partic[name] == 0) {
            partic.erase(name);
        }
    }
    
    map<string,int>::iterator iter;

    string answer = "";

    for(iter=partic.begin();iter!=partic.end();iter++){
        answer = iter->first;
    }

    return answer;
}

int main() {
    cout << solution(vector<string>{"leo", "kiki", "eden"}, vector<string>{"eden", "kiki"}) << endl;
    cout << solution(vector<string>{"marina", "josipa", "nikola", "vinko", "filipa"}, vector<string>{"josipa", "filipa", "marina", "nikola"}) << endl;
    cout << solution(vector<string>{"mislav", "stanko", "mislav", "ana"}, vector<string>{"stanko", "ana", "mislav"}) << endl;
}