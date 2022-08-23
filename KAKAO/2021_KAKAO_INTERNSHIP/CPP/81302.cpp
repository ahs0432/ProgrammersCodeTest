#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> place : places) {
        bool check = true;
        for (int i = 0 ; i < place.size(); i++) {
            for (int j = 0; j < place[i].size(); j++) {
                if (place[i][j] == 'P') {
                    bool up = !(i != 0 && place[i - 1][j] != 'X');
                    bool down = true;
                    bool right = true;

                    if (i != place.size() - 1) {
                        if (place[i + 1][j] == 'P') {
                            check = false;
                            break;
                        } else if (place[i + 1][j] == 'O') {
                            down = false;
                            if (i + 1 != place.size() - 1 && place[i + 2][j] == 'P') {
                                check = false;
                                break;
                            }
                        }
                    }

                    if (j != place[i].size() - 1) {
                        if (place[i][j + 1] == 'P') {
                            check = false;
                            break;
                        } else if (place[i][j + 1] == 'O') {
                            right = false;
                            if (j + 1 != place[i].size() - 1 && place[i][j + 2] == 'P') {
                                check = false;
                                break;
                            }
                        }

                        if (((i != 0) && (!right || !up) && (place[i - 1][j + 1] == 'P')) ||
                            ((i != place.size() - 1) && (!right || !down) && (place[i + 1][j + 1] == 'P'))) {
                            check = false;
                            break;
                        }
                    }
                }
            }
            
            if (!check) {
                break;
            }
        }
        answer.push_back(check);
    }
    
    return answer;
}

int main() {
    for (int i : solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}})) {
        cout << i << " ";
    }

    return 0;
}