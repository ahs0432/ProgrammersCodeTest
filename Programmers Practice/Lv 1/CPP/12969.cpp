#include <string>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
int main(void) {
    int row, col;
    cin >> row >> col;
    
    string s = "";
    for (int i = 0; i < row; i++) {
        s += "*";
    }
    
    for (int i = 0; i < col; i++) {
        cout << s << endl;
    }
    
    return 0;
}