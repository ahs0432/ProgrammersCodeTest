#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// empty 여부 확인을 통해 return 과정에서 -1을 뱉게 할 수 있음
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int a : arr) {
        if (a % divisor == 0) {
            answer.push_back(a);
        }
    }
    if (answer.size() == 0) {
        return {-1};
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}