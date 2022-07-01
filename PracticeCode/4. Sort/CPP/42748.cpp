#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int i, int j) {
    return i > j;
}

// Array를 복사해두고 그 Array 대상에서 정렬 후 처리하는 방법이 존재함
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp = vector<int>{};

    for (vector<int> command : commands) {
        for (int i = command[0]-1; i < command[1]; i++) {
            tmp.push_back(array[i]);
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[command[2]-1]);

        tmp.clear();
    }

    return answer;
}

int main() {
    for (int a : solution(vector<int>{1, 5, 2, 6, 3, 7, 4}, vector<vector<int>>{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}})) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}