#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());

    int answer = 0;
    for (int i = 1; i < citations.size()+1; i++) {
        if (citations[citations.size()-i] < i) {
            break;
        } 
        answer = i;
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{3, 0, 6, 1, 5}) << endl;
    cout << solution(vector<int>{5, 5, 5, 5, 5}) << endl;
}