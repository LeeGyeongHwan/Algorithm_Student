/* 
ACMICPC
Study Group
5th Week
문제 번호 : 17070
문제 제목 : 파이프 옮기기 1
풀이 날짜 : 2020-08-27
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int house[17][17];
bool used[17][17];
int N;
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

int answer = 0;

bool check(int x, int y)
{
    return (x >= 1 && x <= N && y >= 1 && y <= N && !used[x][y] && house[x][y] == 0);
}

void pipe(int x, int y, int mode) //mode: 가로(0), 세로(1), 대각선(2)
{
    if (x == N && y == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if ((mode == 0 && i == 1) || (mode == 1 && i == 0))
            continue;
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (!check(newX, newY))
            continue;

        if (i == 2 && !(house[newX - 1][newY] == 0 && house[newX][newY - 1] == 0))
            continue;
        used[newX][newY] = true;
        pipe(newX, newY, i);
        used[newX][newY] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> house[i][j];
    }

    used[1][1] = true;
    used[1][2] = true;
    pipe(1, 2, 0);

    cout << answer << "\n";
    return 0;
}