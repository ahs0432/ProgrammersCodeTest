#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    int answer = 0;
    
    vector<pair<int, string>> cacheDB(cacheSize, {0, ""});
    
    for (string city : cities) {
        string cityLow = "";
        for (char c : city) cityLow += tolower(c);
        
        bool checked = true;
        for (int i = 0; i < cacheSize; i++) {
            if (cacheDB[i].second == cityLow) {
                cacheDB[i].first = 0;
                checked = false;
                answer += 1;
                continue;
            }
            cacheDB[i].first += 1;
        }
        
        if(checked) {
            cacheDB[0].first = 0;
            cacheDB[0].second = cityLow;
            answer += 5;
        }
        
        sort(cacheDB.begin(), cacheDB.end(), greater<>());
    }
    
    return answer;
}