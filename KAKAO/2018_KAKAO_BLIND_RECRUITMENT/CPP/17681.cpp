#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// 0과 1로 구분하여 True False로 인식하여 #을 추가하는 방식이 존재....
vector<string> arrBitSet(int n, vector<int> arr) {
    vector<string> arrays;
    
    for (int i = 0; i < arr.size(); i++) {
        bitset<16> bs(arr[i]);
        string s = bs.to_string();
        s = s.substr(16 - n);
        arrays.push_back(s);
    }
    
    return arrays;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer = arrBitSet(n, arr1);
    vector<string> array2 = arrBitSet(n, arr2);
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (answer[i][j] == '0') {
                if (array2[i][j] == '1') {
                    answer[i][j] = '#';
                } else {
                    answer[i][j] = ' ';
                }
            } else {
                answer[i][j] = '#';
            }
        }
    }
    
    return answer;
}