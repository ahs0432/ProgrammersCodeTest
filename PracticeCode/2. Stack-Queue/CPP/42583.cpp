#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<int> countTruck(truck_weights.size(), 0);
    int answer = 0;
    int nowWeight = 0;
    int firstTruck = 0;
    int nowTruck = 0;

    while(firstTruck < truck_weights.size()) {
        answer++;
        if (nowTruck < truck_weights.size() && (nowWeight + truck_weights[nowTruck]) <= weight) {
            nowWeight += truck_weights[nowTruck];
            nowTruck += 1;
        }

        for (int i = firstTruck; i < nowTruck; i++) {
            countTruck[i] += 1;
            if (countTruck[i] == bridge_length) {
                nowWeight -= truck_weights[firstTruck];
                firstTruck++;
            }
        }
    }
    
    return answer + 1;
}

int main() {
    cout << solution(2, 10, vector<int>{7,4,5,6}) << endl;
    cout << solution(100, 100, vector<int>{10}) << endl;
    cout << solution(100, 100, vector<int>{10,10,10,10,10,10,10,10,10,10}) << endl;
}