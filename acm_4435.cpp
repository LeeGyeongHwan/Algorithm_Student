/* 
ACMICPC 
문제 번호 : 4435
문제 제목 : 중간계 전쟁
풀이 날짜 : 2020-06-15
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, tmp;

    int G[] = {1, 2, 3, 3, 4, 10};
    int S[] = {1, 2, 2, 2, 3, 5, 10};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int gSum = 0, sSum = 0;
        for (int j = 0; j < 6; j++)
        {
            cin >> tmp;
            gSum += G[j] * tmp;
        }

        for (int k = 0; k < 7; k++)
        {
            cin >> tmp;
            sSum += S[k] * tmp;
        }

        cout << "Battle " << i + 1 << ": ";
        if (gSum > sSum)
            cout << "Good triumphs over Evil" << endl;
        else if (gSum == sSum)
            cout << "No victor on this battle field" << endl;
        else
            cout << "Evil eradicates all trace of Good" << endl;
    }

    return 0;
}