#include <vector>
#include <algorithm>

using namespace std;

// inner_product를 이용하는 방법이 존재함
int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for (int i = 0; i < A.size(); i++) {
        answer += (A[i] * B[i]);
    }

    return answer;
}