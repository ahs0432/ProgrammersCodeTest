#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 정확도 100%
int solution(vector<vector<string>> clothes) {
    map<string, int> clothe;
    for (vector<string> c : clothes) {
        clothe[c[1]] += 1;
    }

    int answer = 0;

    for (map<string, int>::iterator iter = clothe.begin(); iter!=clothe.end(); iter++) {
        if (answer == 0) {
            answer = (iter->second + 1);
        } else {
            answer *= (iter->second + 1);
        }
    }

    answer -= 1;
    return answer;
}

int main() {
    cout << solution(vector<vector<string>>{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    cout << solution(vector<vector<string>>{{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;
    
    return 0;
}