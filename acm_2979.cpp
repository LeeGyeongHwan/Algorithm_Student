/*
ACMICPC
문제 번호 : 2979
문제 제목 : 트럭 주차
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int timeT[101] = {0};
    int cost[4] = {0};
    int A, B, C;
    int enterTime, leftTime;
    for (int i = 1; i <= 3; i++)
        cin >> cost[i];
    for (int i = 0; i < 3; i++)
    {
        cin >> enterTime >> leftTime;
        for (int j = enterTime; j < leftTime; j++)
            timeT[j]++;
    }
    int total = 0;
    for (int i = 1; i < 100; i++)
    {
        total += cost[timeT[i]] * timeT[i];
    }
    cout << total << endl;

    return 0;
}