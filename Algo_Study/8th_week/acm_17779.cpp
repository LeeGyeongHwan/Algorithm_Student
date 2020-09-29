/* 
ACMICPC
Study Group
8th Week
문제 번호 : 17779
문제 제목 : 게리맨더링 2
풀이 날짜 : 2020-09-28
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int population[21][21];
int district[21][21];
int minAbs = INT32_MAX;
int totalSum = 0;
int sumArr[5];

void divideDistrict(int x, int y, int d1, int d2)
{
    if (x + d1 + d2 > N || y - d1 < 1 || y + d2 > N)
        return;
    memset(district, 0, sizeof(district));
    for (int i = 0; i <= d1; i++)
    {
        district[x + i][y - i] = 1;
        district[x + d2 + i][y + d2 - i] = 1;
    }
    for (int i = 0; i <= d2; i++)
    {
        district[x + i][y + i] = 1;
        district[x + d1 + i][y - d1 + i] = 1;
    }
    memset(sumArr, 0, sizeof(sumArr));
    //0번
    for (int i = 1; i < x + d1; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (district[i][j] == 1)
                break;
            sumArr[0] += population[i][j];
        }
    }
    if (sumArr[0] == 0)
        return;
    //1번
    for (int i = 1; i <= x + d2; i++)
    {
        for (int j = N; j > y; j--)
        {
            if (district[i][j] == 1)
                break;
            sumArr[1] += population[i][j];
        }
    }
    if (sumArr[1] == 0)
        return;
    //2번
    for (int i = x + d1; i <= N; i++)
    {
        for (int j = 1; j < y - d1 + d2; j++)
        {
            if (district[i][j] == 1)
                break;
            sumArr[2] += population[i][j];
        }
    }
    if (sumArr[2] == 0)
        return;
    //3번
    for (int i = x + d2 + 1; i <= N; i++)
    {
        for (int j = N; j >= y - d1 + d2; j--)
        {
            if (district[i][j] == 1)
                break;
            sumArr[3] += population[i][j];
        }
    }
    if (sumArr[3] == 0)
        return;
    sumArr[4] = totalSum;
    for (int i = 0; i < 4; i++)
        sumArr[4] -= sumArr[i];

    int minPop = INT32_MAX;
    int maxPop = 0;
    for (int i = 0; i < 5; i++)
    {
        minPop = min(minPop, sumArr[i]);
        maxPop = max(maxPop, sumArr[i]);
    }
    minAbs = min(minAbs, maxPop - minPop);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> population[i][j];
            totalSum += population[i][j];
        }

    for (int i = 1; i <= N; i++)
        for (int j = 2; j <= N - 1; j++)
            for (int d1 = 1; d1 <= N - 1; d1++)
                for (int d2 = 1; d2 <= N - 1; d2++)
                    divideDistrict(i, j, d1, d2);
    cout << minAbs << "\n";
    return 0;
}