#include <string>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string solution(string phone_number) {
    string s = "";
    for (int i = 0; i < phone_number.size() - 4; i++) {
        s += "*";
    }
    phone_number.replace(0, phone_number.size() - 4, s);
    return phone_number;
}