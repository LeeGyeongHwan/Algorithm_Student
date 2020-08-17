/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 2458
문제 제목 : 키 순서
풀이 날짜 : 2020-08-17  
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tallA[501][501];
int shortA[501][501];

int maxNum = 30000;
int main()
{
    vector<int> intVec;

    int N, M;
    int a, b;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            tallA[i][j] = maxNum;
            shortA[i][j] = maxNum;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        tallA[a][b] = 1;
        shortA[b][a] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                {
                    tallA[i][j] = 0;
                    shortA[i][j] = 0;
                    continue;
                }
                tallA[i][j] = min(tallA[i][j], tallA[i][k] + tallA[k][j]);
                shortA[i][j] = min(shortA[i][j], shortA[i][k] + shortA[k][j]);
            }
        }
    }
    int total = 0;
    for (int i = 1; i <= N; i++)
    {
        int student = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            if (tallA[i][j] != maxNum)
                student++;
            if (shortA[i][j] != maxNum)
                student++;
        }
        if (student == N - 1)
            total++;
    }
    cout << total << endl;

    return 0;
}