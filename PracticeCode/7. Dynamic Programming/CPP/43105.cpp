#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 정확성에서도 TimeOut
int dfs(vector<vector<int>> triangle, int row, int col, int sum) {
    if (triangle.size() == col) {
        return sum;
    }

    sum += triangle[col][row];

    int nowSum1 = dfs(triangle, row, col + 1, sum);
    int nowSum2 = dfs(triangle, row + 1, col + 1, sum);

    if (nowSum1 >= nowSum2) {
        return nowSum1;
    }
    return nowSum2;
}

int solution(vector<vector<int>> triangle) {
    return dfs(triangle, 0, 0, 0);
}

int main() {
    cout << solution(vector<vector<int>>{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
}