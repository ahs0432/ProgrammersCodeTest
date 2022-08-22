#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제

// 그냥 미리 순서를 배정하는 것이 아니라 갖고 있는 연산자에 대해서만 계산하기 위해 만듬.
// 근데 이거보다 그냥 지정해두고 하는게 더 빨랐을거 같기도 하다......
vector<queue<char>> operOrderCalc(vector<char> operList, vector<bool> operCheck, queue<char> operOrder, int num) {
    operOrder.push(operList[num]);
    operCheck[num] = true;

    vector<queue<char>> operOrders;
    for (int i = 0; i < operList.size(); i++) {
        if (operCheck[i]) {
            continue;
        }
        vector<queue<char>> operOrderTmp = operOrderCalc(operList, operCheck, operOrder, i);
        operOrders.insert(operOrders.end(), operOrderTmp.begin(), operOrderTmp.end());
    }

    if (operOrders.empty()) {
        return vector<queue<char>>{operOrder};
    }

    return operOrders;
}

long long expressionCalc(vector<long long> nums, vector<char> opers, queue<char> operOrder) {
    char nowOper = operOrder.front();
    operOrder.pop();

    for (int i = 0; i < opers.size();) {
        if (opers[i] == nowOper) {
            if (nowOper == '+') {
                nums[i] = nums[i] + nums[i + 1];
            } else if (nowOper == '-') {
                nums[i] = nums[i] - nums[i + 1];
            } else {
                nums[i] = nums[i] * nums[i + 1];
            }

            opers.erase(opers.begin() + i);
            nums.erase(nums.begin() + (i + 1));
        } else {
            i++;
        }
    }

    if (operOrder.empty()) {
        return nums[0];
    }
    return expressionCalc(nums, opers, operOrder);
}

long long solution(string expression) {
    set<char> operCheck;
    vector<long long> nums;
    vector<char> opers;

    int num = 0;
    for (char e : expression) {
        if (e == '+' || e == '-' || e == '*') {
            opers.push_back(e);
            operCheck.insert(e);
            nums.push_back(num);
            num = 0;
        } else {
            num = (num * 10) + (e - 48);
        }
    }
    nums.push_back(num);

    vector<char> operList;
    for (char oper : operCheck) {
        operList.push_back(oper);
    }

    vector<queue<char>> operOrders;
    for (int i = 0; i < operList.size(); i++) {
        vector<queue<char>> operOrderTmp = operOrderCalc(operList, vector<bool>(operList.size()), queue<char>{}, i);
        operOrders.insert(operOrders.end(), operOrderTmp.begin(), operOrderTmp.end());
    }
    
    long long answer = 0;
    
    for (queue<char> operOrder : operOrders) {
        long long tmp = abs(expressionCalc(nums, opers, operOrder));
        if (tmp > answer) {
            answer = tmp;
        }
    }

    return answer;
}

int main() {
    cout << solution("100-200*300-500+20") << endl;
    cout << solution("50*6-3*2") << endl;

    return 0;
}