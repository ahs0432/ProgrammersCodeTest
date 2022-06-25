#include <string>
#include <vector>
#include <iostream>

using namespace std;

// max_element 함수를 이용한 더 단순한 처리가 가능함
int solution(vector<int> priorities, int location) {
    for (int i = 0; i < priorities.size(); i++) {
        for (int j = i+1; j < priorities.size(); j++) {
            if (priorities[i] < priorities[j]) {
                priorities.push_back(priorities[i]);
                priorities.erase(priorities.begin()+i);
                if (i == location) {
                    location = priorities.size()-1;
                } else if (location > i) {
                    location -= 1;
                }
                i--;
                break;
            }
        }
    }

    return location+1;
}

int main() {
    cout << solution(vector<int>{2, 1, 3, 2}, 2) << endl;
    cout << solution(vector<int>{1, 1, 9, 1, 1, 1}, 0) << endl;

    return 0;
}