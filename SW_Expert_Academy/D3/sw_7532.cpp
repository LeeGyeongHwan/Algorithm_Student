/*
난이도 : D3
문제 번호 : 7532
문제 제목 : 세영이의 SEM력 연도
풀이 날짜 : 2020-02-19
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, S, E, M;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int year;
        cin >> S >> E >> M;
        S = (S == 365) ? 0 : S;
        E = (E == 24) ? 0 : E;
        M = (M == 29) ? 0 : M;

        for (int j = 1;; j++)
        {
            if (j % 365 == S && j % 24 == E && j % 29 == M)
            {
                year = j;
                break;
            }
        }

        cout << "#" << (i + 1) << " " << year << "\n";
    }
    return 0;
}