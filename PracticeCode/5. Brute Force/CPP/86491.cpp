#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int min = 0;
    int max = 0;
    
    for (vector<int> size : sizes) {
        if (size[0] < size[1]) {
            if (min < size[0]) {
                min = size[0];
            }
            
            if (max < size[1]) {
                max = size[1];
            }
        } else {
            if (min < size[1]) {
                min = size[1];
            }
            
            if (max < size[0]) {
                max = size[0];
            }
        }
    }
    
    return max * min;
}