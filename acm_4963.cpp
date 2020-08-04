/*
ACMICPC
문제 번호 : 4963
문제 제목 : 섬의 개수
풀이 날짜 : 2020-08-04
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, tmp;
    int map[50][50];
    bool isVisit[50][50];
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    queue<pair<int, int>> pairQ;

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        memset(map, 0, sizeof(map));
        memset(isVisit, 0, sizeof(isVisit));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> tmp;
                map[i][j] = tmp;
            }
        }
        int land = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!isVisit[i][j] && map[i][j] == 1)
                {
                    land++;
                    pairQ.push(make_pair(i, j));
                    isVisit[i][j] = true;

                    while (!pairQ.empty())
                    {
                        int x, y;
                        tie(x, y) = pairQ.front();
                        pairQ.pop();
                        for (int k = 0; k < 8; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            if (newX >= 0 && newX < h && newY >= 0 && newY < w && !isVisit[newX][newY] && map[newX][newY] == 1)
                            {
                                isVisit[newX][newY] = true;
                                pairQ.push(make_pair(newX, newY));
                            }
                        }
                    }
                }
            }
        }
        cout << land << "\n";
    }

    return 0;
}