/*
ACMICPC
문제 번호 : 14916
문제 제목 : 거스름돈
풀이 날짜 : 2021-03-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int money;
    cin >> money;

    int coinNum = money / 5;
    int rest = money % 5;
    int answer;
    if (rest % 2 == 1)
    {
        if (coinNum == 0)
            answer = -1;
        else
            answer = coinNum - 1 + (rest + 5) / 2;
    }
    else
    {
        answer = coinNum + rest / 2;
    }
    cout << answer << endl;
    return 0;
}