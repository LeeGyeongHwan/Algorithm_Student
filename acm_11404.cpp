/* 
ACMICPC 
문제 번호 : 11404
문제 제목 : 플로이드
풀이 날짜 : 2020-08-05
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int from, to, cost;
    int city[101][101] = {0};
    int maxNum = 100000000;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            city[i][j] = maxNum;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        if (city[from][to] < cost)
            continue;
        city[from][to] = cost;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {

                    city[i][j] = 0;
                    continue;
                }
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == maxNum)
                city[i][j] = 0;
            cout << city[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}