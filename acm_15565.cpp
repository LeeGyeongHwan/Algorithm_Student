/*
ACMICPC
문제 번호 : 15565
문제 제목 : 귀여운 라이언
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>
using namespace std;

int doll[1000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> doll[i];

    int start = 0, end = 0, minSize = 1000000, lionCnt = 0;

    while (true)
    {
        if (lionCnt >= K)
        {
            if (doll[start++] == 1)
                lionCnt--;
        }
        else if (end == N)
            break;
        else
        {
            if (doll[end++] == 1)
                lionCnt++;
        }

        if (lionCnt >= K && end - start < minSize)
            minSize = end - start;
    }

    if (minSize == 1000000)
        cout << "-1\n";
    else
        cout << minSize << "\n";

    return 0;
}