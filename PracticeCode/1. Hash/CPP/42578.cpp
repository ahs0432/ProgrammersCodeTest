#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 정확성 96.4%, TC 1 Timeout
int dfs(map<string, vector<string>> clothe, bool putOn) {
    int total = 0;

    if (clothe.size() == 1) {
        if (putOn) {
            total += 1;
        }
        total += clothe.begin()->second.size();
    } else {
        int count = clothe.begin()->second.size() + 1;
        clothe.erase(clothe.begin()->first);
        
        for (int i = 0; i < count; i++) {
            if (i == 0) {
                total += dfs(clothe, putOn);
            } else {
                total += dfs(clothe, true);
            }
        }
    }

    return total;
}

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> clothe;

    for (vector<string> c : clothes) {
        if (clothe[c[1]].empty()) {
            clothe[c[1]] = vector<string>{c[0]};
        } else {
            clothe[c[1]].push_back(c[0]);
        }
    }

    if (clothe.size() == 1) {
        return clothes.size();
    }

    int answer = dfs(clothe, false);
    
    return answer;
}

int main() {
    cout << solution(vector<vector<string>>{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    cout << solution(vector<vector<string>>{{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;
    return 0;
}