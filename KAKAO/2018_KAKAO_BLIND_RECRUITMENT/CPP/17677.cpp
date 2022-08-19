#include <string>
#include <vector>
#include <set>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
string toUpper(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    
    return str;
}

vector<string> stringSplit(string str) {
    vector<string> result;
    for (int i = 0; i < str.size() - 1; i++) {
        if (((str[i] >= 'A' && str[i] <= 'Z')) && ((str[i + 1] >= 'A' && str[i + 1] <= 'Z'))) {
            result.push_back(str.substr(i, 2));
        } else {
            continue;
        }
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = toUpper(str1);
    str2 = toUpper(str2);
    
    if (str1 == str2) {
        return 65536;
    }
    
    vector<string> strSplit1 = stringSplit(str1);
    vector<string> strSplit2 = stringSplit(str2);
    
    vector<string> strIntersection;
    vector<string> strUnion;
    
    for (int i = 0; i < strSplit1.size(); i++) {
        for (int j = 0; j < strSplit2.size(); j++) {
            if (strSplit1[i] == strSplit2[j]) {
                strSplit2.erase(strSplit2.begin() + j);
                strIntersection.push_back(strSplit1[i]);
                break;
            }
        }
        strUnion.push_back(strSplit1[i]);
    }
    
    strUnion.insert(strUnion.end(), strSplit2.begin(), strSplit2.end());
    
    return 65536 * (float(strIntersection.size()) / float(strUnion.size()));
}