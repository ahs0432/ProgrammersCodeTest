#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> numberCalc(int lastNum, string numbers, string nowNumber) {
    numbers.erase(numbers.begin()+lastNum);

    vector<int> nums = vector<int>{};

    for (int i = 0; i < numbers.size(); i++) {
        string addNum = nowNumber + to_string(numbers[i]-48);
        nums.push_back(stoi(addNum));
        vector<int> tmp = numberCalc(i, numbers, addNum);
        nums.insert(nums.end(), tmp.begin(), tmp.end());
    } 

    return nums;
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> prime(pow(10, numbers.size()));
    vector<bool> checkPrime(pow(10, numbers.size()));

    for (int i = 2; i < prime.size(); i++) {
        if (prime[i] == false) {
            for (int j = i*2; j < prime.size(); j += i) {
                prime[j] = true;
            }
        }
    }

    for (int i = 0; i < prime.size(); i++) {
        prime[i] = !prime[i];
    }

    for (int i = 0; i < numbers.size(); i++) {
        if ((numbers[i] != '0' && numbers[i] != '1') && prime[numbers[i]-48]) {
            if (!checkPrime[numbers[i]-48]) {
                checkPrime[numbers[i]-48] = true;
                answer++;
            }
        }

        vector<int> nums;

        if (numbers[i] == '0') {
            continue;
        } else {
            nums = numberCalc(i, numbers, to_string(numbers[i]-48));

            for (int num : nums) {
                if (!checkPrime[num] && prime[num]) {
                    checkPrime[num] = true;
                    answer++;
                }
            }
        }
    } 

    return answer;
}

int main() {
    cout << solution("17") << endl;
    cout << solution("011") << endl;

    return 0;
}