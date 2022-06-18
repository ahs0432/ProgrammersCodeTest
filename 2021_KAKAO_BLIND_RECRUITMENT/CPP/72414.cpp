#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// 정확도 100%
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

string timeFormat(int a) {
    if (a == 0) {
        return "00";
    } else if (a < 10) {
        return "0" + to_string(a);
    } else {
        return to_string(a);
    }
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

    vector<int> totalTime(playTime+1);

    for (string log : logs) {
        vector<string> times = split(log, '-');
        int startTime = splitTime(times[0]);
        int endTime = splitTime(times[1]);
        if (playTime < startTime || playTime < endTime) {
            continue;
        }

        totalTime[startTime] += 1;
        totalTime[endTime] -= 1;
    }

    for (int i = 1; i < playTime; i++) {
        totalTime[i] += totalTime[i-1];
    }

    long nowTime = 0;

    for (int i = 0; i < advTime-1; i++) {
        nowTime += totalTime[i];
    }

    int answer = 0;
    long topTime = nowTime;

    for (int i = advTime; i < playTime; i++) {
        nowTime -= totalTime[i-advTime];
        nowTime += totalTime[i];

        if (topTime < nowTime) {
            topTime = nowTime;
            answer = i-(advTime-1);
        }
    }

    if (answer == 0) {
        return "00:00:00";
    }

    return timeFormat(answer/60/60) + ":" + timeFormat(answer/60%60) + ":" + timeFormat(answer%60);
}

int main() {
    cout << solution("02:03:55", "00:14:15", vector<string>{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"}) << endl;
    cout << solution("99:59:59", "25:00:00", vector<string>{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"}) << endl;
    cout << solution("50:00:00", "50:00:00", vector<string>{"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"}) << endl;

    return 0;
}