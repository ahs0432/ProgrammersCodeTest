#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> chest(n, vector<int>());
    
    // 삼각형 만들기
    for (int i = 0; i < n; i++) {
        chest[i].push_back(0);
        for (int j = 0; j < i; j++) {
            chest[i].push_back(0);
        }
    }
    
    int in = 0;
    int nowNum = 1;
    
    while ((in * 3) < n) {
        for (int i = (in * 2); i < (n - in); i++) {
            chest[i][in] = nowNum++;
        }
        
        for (int i = in + 1; i < (n - (in * 2)); i++) {
            chest[(n - in) - 1][i] = nowNum++;
        }

        for (int i = (n - in) - 2; i > (in * 2); i--) {
            chest[i][chest[i].size() - in - 1] = nowNum++;
        }

        in++;
    }
    
    for (vector<int> c : chest) {
        answer.insert(answer.end(), c.begin(), c.end());
    }
    
    return answer;
}