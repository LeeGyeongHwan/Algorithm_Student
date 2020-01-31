/*
난이도 : D2
문제 번호 : 1204
문제 제목 : 최빈수 구하기
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int testCase, testNum, tmp;
    int score[101] = {0};

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> testNum;
        int maxScore = 0, freqNum = 0;
        for (int j = 0; j < 1000; j++)
        {
            cin >> tmp;
            score[tmp]++;
        }
        for (int k = 0; k < 101; k++)
        {
            if (score[k] >= maxScore)
            {
                maxScore = score[k];
                freqNum = k;
            }
        }
        cout << "#" << testNum << " " << freqNum << endl;
        memset(score, 0, sizeof(score));
    }
    return 0;
}