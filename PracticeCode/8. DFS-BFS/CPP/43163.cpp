#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkWord(string begin, string after) {
    if (begin == after) {
        return false;
    }

    string tmpBegin = "";
    for (int i = 0; i < begin.size(); i++) {
        tmpBegin = begin;
        tmpBegin[i] = after[i];
        if (tmpBegin == after) {
            return true;
        }
    }

    return false;
}

vector<int> searchWord(string begin, string target, vector<string> words) {
    vector<int> ableWords;
    for (int i = 0; i < words.size(); i++) {
        if (checkWord(begin, words[i])) {
            if (words[i] == target) {
                ableWords = vector<int>{i};
                break;
            }
            ableWords.push_back(i);
        }
    }
    return ableWords;
}

int dfs(int begin, string target, vector<string> words, int moveCount) {
    if (words[begin] == target) {
        return moveCount;
    }

    string tmpWord = words[begin];
    words.erase(words.begin() + begin);
    vector<int> afterList = searchWord(tmpWord, target, words);
    int nowCount = 0;

    for (int after : afterList) {
        int moving = dfs(after, target, words, moveCount + 1);
        if (moving < nowCount || nowCount == 0) {
            nowCount = moving;
        }
    }

    return nowCount;
}

int solution(string begin, string target, vector<string> words) {
    if (begin == target) {
        return 0;
    }

    bool checkWords = false;
    for (string check : words) {
        if (check == target) {
            checkWords = true;
            break;
        }
    }
    if (!checkWords) {
        return 0;
    }

    int answer = 0;
    vector<int> afterList = searchWord(begin, target, words);

    for (int after : afterList) {
        int moveCount = dfs(after, target, words, 1);
        if (moveCount != 0) {
            if (answer == 0) {
                answer = moveCount;
            } else if (moveCount < answer) {
                answer = moveCount;
            }
        }
    }

    return answer;
}

int main() {
    cout << solution("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    cout << solution("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"}) << endl;

    return 0;
}