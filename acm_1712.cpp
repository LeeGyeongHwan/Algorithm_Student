/*
ACMICPC
문제 번호 : 1712
문제 제목 : 손익분기점
풀이 날짜 : 2020-08-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    if (B >= C)
        cout << "-1" << endl;
    else
    {
        int day = A / (C - B);
        cout << day + 1 << endl;
    }

    return 0;
}