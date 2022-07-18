#include <vector>
#include <set>
#include <iostream>

using namespace std;

// Unique 함수를 통한 한번에 해결 가능..
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int a : arr) {
        if (answer.size() != 0) {
            if (answer.back() != a) {
                answer.push_back(a);
            }
        } else {
            answer.push_back(a);
        }
    }
    
    return answer;
}