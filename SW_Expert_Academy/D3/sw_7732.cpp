/*
난이도 : D3
문제 번호 : 7732
문제 제목 : 시간 개념 
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    vector<int> intVec;
    string startTime, endTime;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        string answer = "";
        int startH, startM, startS, endH, endM, endS, answerH, answerM, answerS;
        cin >> startTime >> endTime;
        startH = stoi(startTime.substr(0, 2));
        startM = stoi(startTime.substr(3, 2));
        startS = stoi(startTime.substr(6, 2));

        endH = stoi(endTime.substr(0, 2));
        endM = stoi(endTime.substr(3, 2));
        endS = stoi(endTime.substr(6, 2));

        answerS = endS - startS;
        if (endS < startS)
        {
            answerS += 60;
            endM--;
        }
        answerM = endM - startM;
        if (endM < startM)
        {
            answerM += 60;
            endH--;
        }
        answerH = endH - startH;
        if (endH < startH)
        {
            answerH += 24;
        }

        if (answerH < 10)
            answer += "0";
        answer += to_string(answerH) + ":";
        if (answerM < 10)
            answer += "0";
        answer += to_string(answerM) + ":";
        if (answerS < 10)
            answer += "0";
        answer += to_string(answerS);

        cout << "#" << (i + 1) << " " << answer << endl;
        intVec.clear();
    }
    return 0;
}