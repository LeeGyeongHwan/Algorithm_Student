/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 5567
문제 제목 : 결혼식
풀이 날짜 : 2020-08-06
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#define MAXNUM 1000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int friendship[501][501] = {0};
    int relationA, relationB;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                friendship[i][j] = 0;
            else
                friendship[i][j] = MAXNUM;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> relationA >> relationB;
        friendship[relationA][relationB] = 1;
        friendship[relationB][relationA] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                friendship[i][j] = min(friendship[i][j], friendship[i][k] + friendship[k][j]);
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        if (friendship[1][i] <= 2)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}