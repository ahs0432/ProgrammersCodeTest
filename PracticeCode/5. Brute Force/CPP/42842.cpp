#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i != 0) {
            continue;
        }
        
        if (brown == (((yellow/i)+1)*2 + (i+1)*2)) {
            answer = vector<int>{(yellow/i)+2, i+2};
            break;
        }
    }

    return answer;
}

int main() {
    for (int a : solution(10, 2)) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(8, 1)) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(24, 24)) {
        cout << a << " ";
    }
    cout << endl;
}