#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 한번의 for문을 통한 처리가 가능함
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int loc = 0;
    vector<int> answer;

    while(loc < progresses.size()) {
        for (int i = loc; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        int comp = 0;
        for (int i = loc; i < progresses.size(); i++) {
            if (progresses[i] >= 100) {
                comp += 1;
                loc = i + 1;
            } else {
                break;
            }
        }

        if (comp != 0) {
            answer.push_back(comp);
        }   
    }

    return answer;
}

int main() {
    for (int a : solution(vector<int>{93, 30, 55}, vector<int>{1, 30, 5})) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(vector<int>{95, 90, 99, 99, 80, 99}, vector<int>{1, 1, 1, 1, 1, 1})) {
        cout << a << " ";
    }
    cout << endl;
}