#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// MultiSet을 이용한 풀이 방식이 존재하는 것으로 보임
vector<int> solution(vector<string> operations) {
    bool lastOption = true;
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    int min_pull_size = 0;
    int max_pull_size = 0;

    for (string operation : operations) {
        if (operation == "D 1") {
            if (max.size() != 0){
                max.pop();
                if (min.size() == 1) {
                    min.pop();
                    if (max.size()-min_pull_size == 0) {
                        priority_queue<int> clear_max;
                        swap(max, clear_max);
                        priority_queue<int, vector<int>, greater<int>> clear_min;
                        swap(min, clear_min);
                    }
                    max_pull_size = 0;
                    min_pull_size = 0;
                } else {
                    max_pull_size++;
                    if (max.size()-min_pull_size == 0) {
                        min_pull_size = 0;
                        max_pull_size = 0;
                        priority_queue<int> clear_max;
                        swap(max, clear_max);
                        priority_queue<int, vector<int>, greater<int>> clear_min;
                        swap(min, clear_min);
                    }
                }
            }
        } else if (operation == "D -1") {
            if (min.size() != 0){
                min.pop();
                if (max.size() == 1) {
                    max.pop();
                    if (min.size()-max_pull_size == 0) {
                        priority_queue<int> clear_max;
                        swap(max, clear_max);
                        priority_queue<int, vector<int>, greater<int>> clear_min;
                        swap(min, clear_min);
                    }
                    max_pull_size = 0;
                    min_pull_size = 0;
                } else {
                    min_pull_size++;
                    if (min.size()-max_pull_size == 0) {
                        min_pull_size = 0;
                        max_pull_size = 0;
                        priority_queue<int> clear_max;
                        swap(max, clear_max);
                        priority_queue<int, vector<int>, greater<int>> clear_min;
                        swap(min, clear_min);
                    }
                }
            }
        } else {
            int val = stoi(operation.substr(2));
            min.push(val);
            max.push(val);
        }
    }

    if (max.size() == 0 || min.size() == 0 || max.size()-min_pull_size <= 0 || min.size()-min_pull_size <= 0) {
        return vector<int>{0, 0};
    }

    return vector<int>{max.top(), min.top()};
}

int main() {
    for (int a : solution(vector<string>{"I 16","D 1"})) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : solution(vector<string>{"I 7","I 5","I -5","D -1"})) {
        cout << a << " ";
    }
    cout << endl;
    
    // 6 5
    for (int a : solution(vector<string>{"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"})) {
        cout << a << " ";
    }
    cout << endl;


}