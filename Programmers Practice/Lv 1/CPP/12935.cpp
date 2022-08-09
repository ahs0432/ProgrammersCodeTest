#include <vector>
#include <algorithm>

using namespace std;

// 오늘의 문제 최상단에 위치하여 해결한 문제
// if를 한줄로 표현해서 {-1} 배열을 넘길걸 싶었다는.. 생각
vector<int> solution(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    
    if (arr.empty()) {
        arr.push_back(-1);
    }
    
    return arr;
}