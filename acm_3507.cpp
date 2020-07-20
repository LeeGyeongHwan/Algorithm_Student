/*
ACMICPC
문제 번호 : 3507
문제 제목 : Automated Telephone Exchange
풀이 날짜 : 2020-07-21
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int ATE;
    int answer = 0;

    cin >> ATE;

    for (int i = 0; i < ATE; i++)
    {
        if (i < 100 && ATE - i < 100)
            answer++;
    }
    cout << answer << endl;
    return 0;
}