#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> questions = vector<vector<int>>{{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> count(questions.size());

    for (int nowLoc = 0; nowLoc < answers.size(); nowLoc++) {
        for (int i = 0; i < questions.size(); i++) {
            if (questions[i][nowLoc%questions[i].size()] == answers[nowLoc]) {
                count[i]++;
            }
        }
    }

    vector<int> tops;
    int topCount = 0;

    for (int i = 0; i < questions.size(); i++) {
        if (topCount < count[i]) {
            tops = vector<int>{i+1};
            topCount = count[i];
        } else if (topCount == count[i]) {
            tops.push_back(i+1);
        }
    }

    return tops;
}

int main() {
    for (int a : solution(vector<int>{1,2,3,4,5})){
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(vector<int>{1,3,2,4,2})){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}