/*
ACMICPC
문제 번호 : 14681
문제 제목 : 사분면 고르기
풀이 날짜 : 2020-04-09
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    int answer;
    cin >> x >> y;

    if (x > 0)
    {
        if (y > 0)
            answer = 1;
        else
            answer = 4;
    }
    else
    {
        if (y > 0)
            answer = 2;
        else
            answer = 3;
    }
    cout << answer << endl;

    return 0;
}