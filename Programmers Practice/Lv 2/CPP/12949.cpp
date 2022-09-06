#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (vector<int> arr : arr1) {
        answer.push_back({});
        for (int i = 0; i < arr2[0].size(); i++) {
            int result = 0;
            for (int j = 0; j < arr.size(); j++) {
                result += (arr2[j][i] * arr[j]);
            }
            answer.back().push_back(result);
        }
    }
    
    return answer;
}