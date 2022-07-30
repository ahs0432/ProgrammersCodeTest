#include <string>
#include <vector>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> month_date = {31,29,31,30,31,30,31,31,30,31,30,31};
vector<string> week_name = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    int total = b;
    for (int i = 1; i < a; i++) {
        total += month_date[i-1];
    }
    return week_name[(total%7)];
}