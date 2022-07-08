#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    for (int c = 0; c < k; c++) {
        for (int i = 0; i < number.size(); i++) {
            if (i == number.size()-1) {
                number.erase(i);
                break;
            }

            if (number[i] < number[i+1]) {
                number.erase(number.begin() + i);
                break;
            }
        }
    }
    
    
    return number;
}

int main() {
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}