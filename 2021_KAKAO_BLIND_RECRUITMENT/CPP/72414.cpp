#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// 정확도 22.6%
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int splitTime(string timeString) {
    vector<string> timeStringSplit = split(timeString, ':');
    int time = ((stoi(timeStringSplit[0]) * 60) * 60) + (stoi(timeStringSplit[1]) * 60) + stoi(timeStringSplit[2]);

    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    if (play_time == adv_time) {
        return "00:00:00";
    }

    int playTime = splitTime(play_time);
    int advTime = splitTime(adv_time);

    if (playTime < advTime) {
        return "00:00:00";
    }

    vector<vector<int>> logTime = vector<vector<int>>{{}, {}, {}};

    for (string log : logs) {
        vector<string> times = split(log, '-');

        logTime[0].push_back(splitTime(times[0]));
        logTime[1].push_back(splitTime(times[1]));
        logTime[2].push_back(logTime[1].back()-logTime[0].back());
    }

    vector<vector<vector<int>>> includeTime;

    int topTime = 0;
    int answer = 0;

    for (int i = 0; i < logTime[0].size(); i++) {
        int totalTime = 0;
        int startTime = logTime[0][i];
        int endTime = logTime[0][i] + advTime;
        
        if (logTime[2][i] < advTime) {
            totalTime = logTime[2][i];
        } else {
            totalTime = advTime;
        }

        for (int j = 0; j < logTime[0].size(); j++) {
            if (j == i) {
                continue;
            }

            if (startTime <= logTime[0][j] && endTime >= logTime[0][j]) {
                if (endTime >= logTime[1][j]) {
                    totalTime += logTime[2][j];
                } else {
                    totalTime += endTime - logTime[0][j];
                }
            } else if (startTime <= logTime[1][j] && endTime >= logTime[1][j]) {
                totalTime += logTime[1][j] - startTime;
            }
        }

        if (topTime < totalTime) {
            topTime = totalTime;
            answer = i;
        } else if (topTime == totalTime && logTime[0][i] < logTime[0][answer]) {
            answer = i;
        }
    }

    return split(logs[answer], '-')[0];
}

int main() {
    cout << solution("02:03:55", "00:14:15", vector<string>{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"}) << endl;
    cout << solution("99:59:59", "25:00:00", vector<string>{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"}) << endl;
    cout << solution("50:00:00", "50:00:00", vector<string>{"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"}) << endl;

    return 0;
}