/*
난이도 : D3
문제 번호 : 7272
문제 제목 : 안경이 없어!
풀이 날짜 : 2020-02-19
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    string strA, strB;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        bool isDifferent = false;
        cin >> strA >> strB;

        if (strA.size() != strB.size())
            isDifferent = true;
        else
        {
            for (int j = 0; j < strA.size(); j++)
            {
                if (strA[j] == 'B')
                {
                    if (strB[j] != 'B')
                    {
                        isDifferent = true;
                        break;
                    }
                }
                else if (strA[j] == 'A' || strA[j] == 'D' || strA[j] == 'O' || strA[j] == 'P' || strA[j] == 'Q' || strA[j] == 'R')
                {
                    if (!(strB[j] == 'A' || strB[j] == 'D' || strB[j] == 'O' || strB[j] == 'P' || strB[j] == 'Q' || strB[j] == 'R'))
                    {
                        isDifferent = true;
                        break;
                    }
                }
                else
                {
                    if (strB[j] == 'A' || strB[j] == 'D' || strB[j] == 'O' || strB[j] == 'P' || strB[j] == 'Q' || strB[j] == 'R' || strB[j] == 'B')
                    {
                        isDifferent = true;
                        break;
                    }
                }
            }
        }

        if (isDifferent)
            cout << "#" << (i + 1) << " DIFF\n";
        else
            cout << "#" << (i + 1) << " SAME\n";
    }
    return 0;
}