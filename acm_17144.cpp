/* 
ACMICPC 
문제 번호 : 17144
문제 제목 : 미세먼지 안녕!
풀이 날짜 : 2020-08-01
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int R, C, T, tmp;
    int room[50][50] = {0};
    int tmpRoom[50][50] = {0};

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<pair<int, int>> pairQ;

    int air1 = -1;
    int air2;

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> tmp;
            room[i][j] = tmp;
            if (tmp == -1)
            {
                if (air1 == -1)
                    air1 = i;
                else
                    air2 = i;
            }
        }
    }

    for (int timer = 0; timer < T; timer++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (room[i][j] >= 5)
                {
                    int way = 0;
                    int dust = room[i][j] / 5;

                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < R && y >= 0 && y < C && room[x][y] != -1)
                        {
                            tmpRoom[x][y] += dust;
                            way++;
                        }
                    }
                    room[i][j] -= dust * way;
                }
            }
        }
        // 먼지합치기
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                room[i][j] += tmpRoom[i][j];
                tmpRoom[i][j] = 0;
            }
        }
        //공기청정기
        // air1
        int up = 0;
        pairQ.push(make_pair(air1, 0));

        while (!pairQ.empty())
        {
            int x, y;
            tie(x, y) = pairQ.front();
            pairQ.pop();

            int newX = x + dx[up];
            int newY = y + dy[up];

            if (!(newX >= 0 && newX <= air1 && newY >= 0 && newY < C))
            {
                up++;
                up %= 4;
                newX = x + dx[up];
                newY = y + dy[up];
            }

            if (room[newX][newY] == -1)
            {
                room[x][y] = 0;
                while (!pairQ.empty())
                {
                    pairQ.pop();
                }
                break;
            }

            if (room[x][y] != -1)
                room[x][y] = room[newX][newY];
            room[newX][newY] = 0;

            pairQ.push(make_pair(newX, newY));
        }

        int down = 2;
        pairQ.push(make_pair(air2, 0));

        while (!pairQ.empty())
        {
            int x, y;
            tie(x, y) = pairQ.front();
            pairQ.pop();

            int newX = x + dx[down];
            int newY = y + dy[down];

            if (!(newX >= air2 && newX < R && newY >= 0 && newY < C))
            {
                down--;
                if (down < 0)
                    down = 3;
                newX = x + dx[down];
                newY = y + dy[down];
            }

            if (room[newX][newY] == -1)
            {
                room[x][y] = 0;
                while (!pairQ.empty())
                {
                    pairQ.pop();
                }
                break;
            }

            if (room[x][y] != -1)
                room[x][y] = room[newX][newY];
            room[newX][newY] = 0;

            pairQ.push(make_pair(newX, newY));
        }
    }
    //먼지확인
    int dustSum = 2;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dustSum += room[i][j];
        }
    }
    cout << dustSum << endl;
    return 0;
}