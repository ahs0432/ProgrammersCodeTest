#include <string>
#include <vector>

using namespace std;

string toBinary(int n, int i) {
    string result = "";
    string words = "0123456789ABCDEF";
    
    while (i != 0) {
        result = words[i % n] + result;
        i /= n;
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string fullwords = "01";
    int alreadyWord = t * m;
    
    int i = 2;
    
    while (fullwords.size() < alreadyWord) {
        fullwords += toBinary(n, i);
        i++;
    }
    
    for (int i = p - 1; i < alreadyWord; i+=m) {
        answer += fullwords[i];
    }
    
    return answer;
}