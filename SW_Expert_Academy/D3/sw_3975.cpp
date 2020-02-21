/*
난이도 : D3
문제 번호 : 3975
문제 제목 : 승률 비교하기
풀이 날짜 : 2020-02-21
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int boxArr[1001] = {0};

    int testCase, winA, playA, winB, playB;
    double winRateA, winRateB;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> winA >> playA >> winB >> playB;
        winRateA = (double)winA / playA;
        winRateB = (double)winB / playB;

        if (winRateA > winRateB)
            cout << "#" << (i + 1) << " ALICE\n";
        else if (winRateB > winRateA)
            cout << "#" << (i + 1) << " BOB\n";
        else
            cout << "#" << (i + 1) << " DRAW\n";
    }

    return 0;
}