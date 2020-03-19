/*
ACMICPC
문제 번호 : 4118
문제 제목 : Fred’s Lotto Tickets
풀이 날짜 : 2020-03-19
Solved By Reamer
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int testCase, num;
    int lotto[50] = {0};

    while (1)
    {
        int isCover = 1;
        cin >> testCase;
        if (testCase == 0)
            break;

        for (int i = 0; i < testCase; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cin >> num;
                lotto[num] = 1;
            }
        }

        for (int i = 1; i < 50; i++)
        {
            isCover &= lotto[i];
        }
        if (isCover)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        memset(lotto, 0, sizeof(lotto));
    }
    return 0;
}