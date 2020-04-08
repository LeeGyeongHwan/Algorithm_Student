/*
ACMICPC
문제 번호 : 9713
문제 제목 : Sum of Odd Sequence
풀이 날짜 : 2020-04-08
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num, tmp;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int sum = 0;
        cin >> tmp;
        for (int j = 1; j <= tmp; j += 2)
            sum += j;
        cout << sum << endl;
    }

    return 0;
}