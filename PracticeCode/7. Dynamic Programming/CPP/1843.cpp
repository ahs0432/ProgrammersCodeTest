#include <vector>
#include <string>
#include <iostream>

using namespace std;

int min_element(int a, int b) {
    return (a < b ? a : b);
}

int max_element(int a, int b) {
    return (a > b ? a : b);
}

// 뒤에서부터 최소, 최대 값을 구해두고 -가 나올 경우 이전 -와 현재 - 사이 값의 값과 계산하여 최소, 최대 값 재계산
// 조금의 힌트를 확인해본 문제
int solution(vector<string> arr) {
    int sum = stoi(arr.back());
    int max = 0;
    int min = 0;

    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] == "-") {
            int tmpMax = max;
            int tmpMin = min;

            // 모든 수를 더하고(3 + 5) 이전 계산된 최대 값(-8)과 더한 뒤 -로 적용 / -((3 + 5) - 8) 구현
            // 모든 수를 더하고(3 + 5) -로 적용한 뒤 이전 계산된 최소 값(-8)과 덧셈 적용 / (-(3 + 5) - 8) 구현
            min = min_element(-(sum + tmpMax), (-sum + tmpMin));

            // 모든 수를 더하고(3 + 5) 이전 계산된 최소 값(-8)과 더한 뒤 -로 적용 / -((3 + 5) - 8) 구현
            // 모든 수를 더하고(3 + 5) 이전 계산된 최대 값과(-8)과 더한 뒤 이전 수의 두 배를 뺌 / ((3 + 5) - 8) - (3 * 2) = (-3) + (5 - 8) 구현
            max = max_element(-(sum + tmpMin), (sum + tmpMax - (2 * stoi(arr[i + 1]))));
            
            sum = 0;
        } else if (arr[i] == "+") {
            continue;
        } else {
            sum += stoi(arr[i]);
        }
    }

    // 최종 최댓값과 마지막으로 남은 덧셈 숫자를 더함으로 계산 종료
    return max + sum;
}

int main() {
    cout << solution({"1", "-", "3", "+", "5", "-", "8"}) << endl;
    cout << solution({"5", "-", "3", "+", "1", "+", "2", "-", "4"}) << endl;

    return 0;
}