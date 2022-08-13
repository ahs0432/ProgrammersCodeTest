#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {    
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); i++) {
        answer.push_back({});
        for (int j = 0; j < arr1[i].size(); j++) {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    
    return answer;
}