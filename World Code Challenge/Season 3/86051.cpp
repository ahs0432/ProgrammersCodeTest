#include <string>
#include <vector>
#include <map>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 총합에서 빼는 방법도 존재함.
int solution(vector<int> numbers) {
    vector<bool> findNum(10); 
    for (int number : numbers) {
        findNum[number] = true;
    }
    
    int answer = 0;
    for (int i = 1; i < findNum.size(); i++) {
        if (!findNum[i]) {
            answer += i;
        }
    }
    
    return answer;
}