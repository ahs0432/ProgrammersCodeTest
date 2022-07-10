#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// for 문 하나를 이용해서 푸는 방법이 존재함 (First, End를 구분하여...)
// 각 숫자를 POP, Erase 하는 과정에서 많은 시간 소요를 보임 이는 이후에도 참고할 것
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int first = people.size()-1;
    int end = 0;

    while (first >= end) {
        if (people[first] == limit) {
            answer++;
            first--;
            continue;
        }

        if (people[first] <= (limit / 2)) {
            answer += (first - end + 1) / 2 + (first - end + 1) % 2;
            break;
        } else if (first > end && people[first] + people[end] <= limit) {
            end++;
        }

        first--;
        answer++;
    }

    return answer;
}

int main() {
    cout << solution(vector<int>{70, 50, 80, 50}, 100) << endl;
    cout << solution(vector<int>{70, 80, 50}, 100) << endl;
}