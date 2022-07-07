#include <vector>
using namespace std;

// Set을 이용한 방법도 존재하니 확인해볼 것 **
// 오늘의 문제 최상단에 위치하여 해결한 문제
int solution(vector<int> nums) {
    int answer = 0;
    vector<int> numList;
    
    for (int num : nums) {
        bool overlap = false;
        for (int over : numList) {
            if (num == over) {
                overlap = true;
                break;
            }
        }
        
        if (!overlap) {
            numList.push_back(num);
            answer += 1;
            if (numList.size() == nums.size() / 2) {
                break;
            }
        }
    }
    
    return answer;
}