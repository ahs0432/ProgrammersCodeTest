#include <string>
#include <vector>
#include <sstream>

using namespace std;

string split(string input, char delimiter) {
    pair<int, int> sInt = {2147483647, -2147483647};
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        if (sInt.first > stoi(temp)) {
            sInt.first = stoi(temp);
        }
        
        if (sInt.second < stoi(temp)) {
            sInt.second = stoi(temp);
        }
    }
 
    return to_string(sInt.first) + " " + to_string(sInt.second);
}

string solution(string s) {
    return split(s, ' ');
}