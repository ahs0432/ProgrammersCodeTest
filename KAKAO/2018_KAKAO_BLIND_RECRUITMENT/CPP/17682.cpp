#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// pow 명령어를 통해 조금 더 단축 시킬 수 있음
int solution(string dartResult) {
    vector<int> numList(3, 0);
    int nowOrder = 0;
    
    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] >= 48 && dartResult[i] <= 57) {
            numList[nowOrder] *= 10;
            numList[nowOrder] += (dartResult[i] - 48);
        } else {
            if (dartResult[i] == 'D') {
                numList[nowOrder] = (numList[nowOrder] * numList[nowOrder]);
            } else if (dartResult[i] == 'T') {
                numList[nowOrder] = (numList[nowOrder] * numList[nowOrder] * numList[nowOrder]);
            } else if (dartResult[i] == '*') {
                numList[nowOrder-1] *= 2;
                if (nowOrder != 1) {
                    numList[nowOrder-2] *= 2;
                }
                continue;
            } else if (dartResult[i] == '#') {
                numList[nowOrder-1] = -numList[nowOrder-1];
                continue;
            } 
            nowOrder++;
        }
    }
    
    return numList[0] + numList[1] + numList[2];
}