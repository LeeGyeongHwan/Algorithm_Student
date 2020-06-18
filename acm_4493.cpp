/* 
ACMICPC 
문제 번호 : 4493
문제 제목 : 가위 바위 보?
풀이 날짜 : 2020-06-18
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num;
    char P1, P2;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int sumP1 = 0, sumP2 = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> P1 >> P2;

            if (P1 == 'R')
            {
                if (P2 == 'P')
                    sumP2++;
                else if (P2 == 'S')
                    sumP1++;
            }
            else if (P1 == 'P')
            {
                if (P2 == 'S')
                    sumP2++;
                else if (P2 == 'R')
                    sumP1++;
            }
            else
            {
                if (P2 == 'R')
                    sumP2++;
                else if (P2 == 'P')
                    sumP1++;
            }
        }
        if (sumP1 > sumP2)
            cout << "Player 1" << endl;
        else if (sumP1 < sumP2)
            cout << "Player 2" << endl;
        else
            cout << "TIE" << endl;
    }

    return 0;
}