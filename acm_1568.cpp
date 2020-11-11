/*
ACMICPC
문제 번호 : 1568
문제 제목 : 새
풀이 날짜 : 2020-11-12
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    int sing = 1;
    while (N != 0)
    {
        if (N >= sing)
            N -= sing;
        else
        {
            sing = 1;
            continue;
        }
        sing++;
        cnt++;
    }

    cout << cnt << "\n";
}