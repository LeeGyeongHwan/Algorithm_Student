/* 
ACMICPC
Study Group
5th Week
문제 번호 : 1937
문제 제목 : 욕심쟁이 판다
풀이 날짜 : 2020-08-28
Solved By Reamer 
*/

#include <iostream>
using namespace std;

int N;
int forest[500][500];
bool isVisited[500][500];
int dp[500][500];
int maxLifeTime = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y, int bamboo)
{
    return x >= 0 && x < N && y >= 0 && y < N && forest[x][y] > bamboo;
}

int findWay(int x, int y, int day)
{
    int num = 1;
    int maxDay = num;

    if (dp[x][y] != 0)
        return dp[x][y];
    int curBam = forest[x][y];

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (!check(newX, newY, curBam))
            continue;
        int tmp = num + findWay(newX, newY, day + 1);
        if (tmp > maxDay)
            maxDay = tmp;
    }
    dp[x][y] = maxDay;
    return maxDay;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> forest[i][j];
        }
    }
    int maxDay = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int day = findWay(i, j, 1);
            if (maxLifeTime < day)
                maxLifeTime = day;
        }
    }
    cout << maxLifeTime << "\n";

    return 0;
}