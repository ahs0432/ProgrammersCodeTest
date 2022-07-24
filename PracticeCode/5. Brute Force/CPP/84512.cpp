#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Cost가 5씩 곱하는 5의 제곱근 형태이기 때문에 이를 이용한 풀이가 가능함..
int solution(string word) {
    vector<char> words = {'A', 'E', 'I', 'O', 'U'};
    vector<int> wordCost = {781, 156, 31, 6 ,1};
    
    int answer = 0;
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (word[i] == words[j]) {
                answer += 1 + (wordCost[i] * j);
                break;
            }
        }
    }
    return answer;
}

int main() {
    cout << solution("AAAAE") << endl;
    cout << solution("AAAE") << endl;
    cout << solution("I") << endl;
    cout << solution("EIO") << endl;

    return 0;
}