#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0] += triangle[i-1][0];
        for (int j = 1; j < i; j++) {
            triangle[i][j] += *max_element(triangle[i-1].begin() + (j - 1), triangle[i-1].begin() + (j + 1));
        }
        triangle[i][i] += triangle[i-1][i-1];
    }

    return *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
}

int main() {
    cout << solution(vector<vector<int>>{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
}