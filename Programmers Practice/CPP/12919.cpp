#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// find 함수를 이용하여 해소가 가능함
string solution(vector<string> seoul) {
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            return "김서방은 " + to_string(i) + "에 있다";
        }
    }
    return "";
}