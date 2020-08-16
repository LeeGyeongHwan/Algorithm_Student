/* 
ACMICPC 
문제 번호 : 14503
문제 제목 : 로봇 청소기
풀이 날짜 : 2020-08-16
Solved By Reamer 
*/

#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int room[50][50];
    bool isClear[50][50] = {0};
    queue<pair<int, int>> pairQ;

    int N, M;
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    pairQ.push({r, c});
    int clearArea = 0;

    while (!pairQ.empty())
    {
        int x, y;
        tie(x, y) = pairQ.front();
        pairQ.pop();
        if (!isClear[x][y])
        {
            isClear[x][y] = true;
            clearArea++;
        }
        bool canClear = false;
        for (int i = 0; i < 4; i++)
        {
            d--;
            if (d < 0)
                d = 3;
            int newX = x + dx[d];
            int newY = y + dy[d];
            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !isClear[newX][newY] && room[newX][newY] == 0)
            {
                pairQ.push({newX, newY});
                canClear = true;
                break;
            }
        }

        if (!canClear)
        {
            int way = (d + 2) % 4;
            int backX = x + dx[way];
            int backY = y + dy[way];
            if (room[backX][backY] == 1)
                break;
            pairQ.push({backX, backY});
        }
    }
    cout << clearArea << "\n";
    return 0;
}