#include <string>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    map<string, bool> moves;
    
    int x = 0;
    int y = 0;
    
    for (char dir : dirs) {
        string beforeLoc = to_string(x) + to_string(y);
        
        if (dir == 'U') {
            if (y == 5) continue;
            y += 1;
        } else if (dir == 'D') {
            if (y == -5) continue;
            y -= 1;
        } if (dir == 'R') {
            if (x == 5) continue;
            x += 1;
        } else if (dir == 'L') {
            if (x == -5) continue;
            x -= 1;
        }
        
        string nowLoc = to_string(x) + to_string(y);
        
        if (!moves[beforeLoc + nowLoc] && !moves[nowLoc + beforeLoc]) {
            answer++;
            moves[beforeLoc + nowLoc] = true;
            moves[nowLoc + beforeLoc] = true;
        }
    }
    
    return answer;
}