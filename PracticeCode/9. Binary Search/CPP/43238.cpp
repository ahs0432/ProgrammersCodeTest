#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    // 최대 시간 소요 확인
    long long maxTime = times[0] * n;
    long long minTime = 0;
    long long lowTime = 0;

    // 최대 시간 소요 시 Count 수 확인
    long long count = 0;
    for (int time : times) {
        count += maxTime / time;
    }

    while (true) {
        long long tmpTime = minTime + (((maxTime - minTime) / 2));
        
        count = 0;
        for (int time : times) {
            count += tmpTime / time;
        }

        if (count > n) {
            maxTime = tmpTime;
        } else if (count < n) {
            if (minTime == tmpTime) {
                return maxTime;
            }
            minTime = tmpTime;
        } else {
            if (minTime == tmpTime) {
                return maxTime;
            }
            maxTime = tmpTime;
        }
    }

    return maxTime;
}

int main() {
    cout << solution(6, vector<int>{7, 10}) << endl;
    cout << solution(7, vector<int>{7, 10}) << endl;
    cout << solution(2, vector<int>{1,2,2,2,100}) << endl;
    cout << solution(8, vector<int>{5, 7, 12}) << endl;
    cout << solution(10, vector<int>{6, 8, 10}) << endl;

    return 0;
}