#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<int> numbers, int target, int total) {
    if (numbers.empty()) {
        return (total == target);
    }

    int answer = 0;
    int tmpNumber = numbers.back();
    numbers.pop_back();

    answer += dfs(numbers, target, total+tmpNumber);
    answer += dfs(numbers, target, total-tmpNumber);

    return answer;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0);
}

int main() {
    cout << solution(vector<int>{1,1,1,1,1}, 3) << endl;
    cout << solution(vector<int>{4,1,2,1}, 4) << endl;
}