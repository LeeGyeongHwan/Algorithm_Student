/*
ACMICPC
문제 번호 : 2573
문제 제목 : 빙산
풀이 날짜 : 2020-08-05
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int iceLand[300][300] = {0};
int tmpLand[300][300] = {0};
bool isVisited[300][300] = {0};

int main()
{
    int N, M, tmp;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<pair<int, int>> pairQ;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            iceLand[i][j] = tmp;
        }
    }

    int year = 0;
    bool isMelt = false;
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                tmpLand[i][j] = iceLand[i][j];
            }
        }
        int cntLand = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!isVisited[i][j] && iceLand[i][j] != 0)
                {
                    cntLand++;
                    isVisited[i][j] = true;
                    pairQ.push(make_pair(i, j));

                    while (!pairQ.empty())
                    {
                        int x, y;
                        tie(x, y) = pairQ.front();
                        pairQ.pop();
                        int cntSea = 0;
                        for (int k = 0; k < 4; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            if (!(newX >= 0 && newX < N && newY >= 0 && newY < M))
                                continue;
                            if (iceLand[newX][newY] == 0)
                                cntSea++;
                            else if (!isVisited[newX][newY])
                            {
                                isVisited[newX][newY] = true;
                                pairQ.push(make_pair(newX, newY));
                            }
                        }
                        tmpLand[x][y] -= cntSea;
                        if (tmpLand[x][y] < 0)
                            tmpLand[x][y] = 0;
                    }
                }
            }
        }
        if (cntLand == 0)
        {
            isMelt = true;
            break;
        }
        else if (cntLand > 1)
        {
            break;
        }

        year++;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                iceLand[i][j] = tmpLand[i][j];
            }
        }
        memset(isVisited, 0, sizeof(isVisited));
    }
    if (isMelt)
        cout << "0" << endl;
    else
        cout << year << endl;

    return 0;
}