#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] > b[0]) {
        return false;
    } else {
        int aNumInt = stoi(a[1]);
        int bNumInt = stoi(b[1]);
        
        if (aNumInt < bNumInt) {
            return true;
        } else if (aNumInt > bNumInt) {
            return false;
        } else {
            int aIndexInt = stoi(a[2]);
            int bIndexInt = stoi(b[2]);
            
            if (aIndexInt < bIndexInt) {
                return true;
            } else {
                return false;
            }
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> storage;
    
    for (int i = 0; i < files.size(); i++) {
        string file = files[i];
        storage.push_back({"", "", to_string(i), file});
        
        bool type = true;
        int count = 0;
        
        for (int j = 0; j < file.size(); j++) {
            char c = tolower(file[j]);
            
            if (type) {
                if (c >= '0' && c <= '9') {
                    count++;
                    type = false;
                    storage[i][1].push_back(c);
                    continue;
                }
                
                storage[i][0].push_back(c);
            } else {
                if (count == 5) {
                    break;
                } else if (c >= '0' && c <= '9') {
                    count++;
                    storage[i][1].push_back(c);
                } else {
                    break;
                }
            }
        }
        
        storage[i][1] = to_string(stoi(storage[i][1]));
    }
    
    sort(storage.begin(), storage.end(), compare);
    
    for (vector<string> s : storage) {
        answer.push_back(s[3]);
    }
    
    return answer;
}