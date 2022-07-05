#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countName(char c) {
    int min = c - 'A';
    if ((1 + 'Z' - c) < min) {
        return min = (1 + 'Z' - c);
    }
    return min;
}

int calcLoc(int size, int nowLoc, int goalLoc) {
    int min = 0;
    if (nowLoc > goalLoc) {
        min = nowLoc - goalLoc;
        if (min > (size - nowLoc + 1 + goalLoc)) {
            min = (size - nowLoc + 1 + goalLoc);
        }
    } else {
        min = goalLoc - nowLoc;
        if (min > (nowLoc + 1 + size - goalLoc)) {
            min = (nowLoc + 1 + size - goalLoc);
        }
    }
    return min;
}

int countLoc(vector<int> goNum, int count, bool firstC, int nowLoc, int size) {
    if (nowLoc != 0) {
        if (firstC) {
            goNum.erase(goNum.begin());
        } else {
            goNum.pop_back();
        }
    }
    
    if (goNum.empty()) {
        return count;
    }

    int loc1 = countLoc(goNum, count + calcLoc(size, nowLoc, goNum[0]), true, goNum[0], size);
    int loc2 = countLoc(goNum, count + calcLoc(size, nowLoc, goNum.back()), false, goNum.back(), size);
    
    if (loc1 <= loc2) {
        return loc1;
    }
    return loc2;
}

int solution(string name) {
    int answer = 0;
    vector<int> goNum;

    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'A') {
            continue;
        }
        if (i != 0) {
            goNum.push_back(i);
        }
        answer += countName(name[i]);
    }

    return answer + countLoc(goNum, 0, true, 0, name.size()-1);
}

int main() {
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
    cout << solution("ABAAAAAAAAABB") << endl;
}