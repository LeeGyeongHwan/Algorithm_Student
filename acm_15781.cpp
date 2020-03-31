/*
ACMICPC
문제 번호 : 15781
문제 제목 : 헬멧과 조끼
풀이 날짜 : 2020-03-31
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int helmet, vest, tmp;
    int helmetMax = 0, vestMax = 0;
    ;
    cin >> helmet >> vest;

    for (int i = 0; i < helmet; i++)
    {
        cin >> tmp;
        if (tmp > helmetMax)
            helmetMax = tmp;
    }
    for (int i = 0; i < vest; i++)
    {
        cin >> tmp;
        if (tmp > vestMax)
            vestMax = tmp;
    }

    cout << helmetMax + vestMax << endl;
    return 0;
}