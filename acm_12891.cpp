/*
ACMICPC
문제 번호 : 12891
문제 제목 : DNA 비밀번호
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>
#include <string>

using namespace std;

int acgt[4];
int acgtCnt[4] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S, P;
    string pwd;

    cin >> S >> P;
    cin >> pwd;

    for (int i = 0; i < 4; i++)
        cin >> acgt[i];

    int pwCnt = 0;

    for (int i = 0; i < P; i++)
    {
        if (pwd[i] == 'A')
            acgtCnt[0]++;
        else if (pwd[i] == 'C')
            acgtCnt[1]++;
        else if (pwd[i] == 'G')
            acgtCnt[2]++;
        else if (pwd[i] == 'T')
            acgtCnt[3]++;
    }

    if (acgtCnt[0] >= acgt[0] && acgtCnt[1] >= acgt[1] && acgtCnt[2] >= acgt[2] && acgtCnt[3] >= acgt[3])
        pwCnt++;

    for (int i = 0; i < S - P; i++)
    {
        if (pwd[i] != pwd[i + P])
        {
            if (pwd[i] == 'A')
                acgtCnt[0]--;
            else if (pwd[i] == 'C')
                acgtCnt[1]--;
            else if (pwd[i] == 'G')
                acgtCnt[2]--;
            else if (pwd[i] == 'T')
                acgtCnt[3]--;

            if (pwd[i + P] == 'A')
                acgtCnt[0]++;
            else if (pwd[i + P] == 'C')
                acgtCnt[1]++;
            else if (pwd[i + P] == 'G')
                acgtCnt[2]++;
            else if (pwd[i + P] == 'T')
                acgtCnt[3]++;
        }

        if (acgtCnt[0] >= acgt[0] && acgtCnt[1] >= acgt[1] && acgtCnt[2] >= acgt[2] && acgtCnt[3] >= acgt[3])
            pwCnt++;
    }
    cout << pwCnt << "\n";
    return 0;
}