#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size(); i++) {
        int number1 = numbers[i];
        for (int j = (i + 1); j < numbers.size(); j++) {
            answer.push_back(number1 + numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}