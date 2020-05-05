/*
ACMICPC
문제 번호 : 2589
문제 제목 : 보물섬
풀이 날짜 : 2020-05-05
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int main()
{
    char graph[50][50];
    int isVisit[50][50] = {0};
    queue<pair<int, int>> pairQ;
    int maxDistance = 0;
    int N, M;
    string str;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = str[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (graph[i][j] == 'L')
            {
                int lastX, lastY;
                pairQ.push(make_pair(i, j));
                isVisit[i][j] = 1;

                while (!pairQ.empty())
                {
                    int x, y;
                    tie(x, y) = pairQ.front();
                    lastX = x;
                    lastY = y;
                    pairQ.pop();

                    if (x - 1 >= 0 && graph[x - 1][y] == 'L' && !isVisit[x - 1][y])
                    {
                        pairQ.push(make_pair(x - 1, y));
                        isVisit[x - 1][y] = isVisit[x][y] + 1;
                    }
                    if (y - 1 >= 0 && graph[x][y - 1] == 'L' && !isVisit[x][y - 1])
                    {
                        pairQ.push(make_pair(x, y - 1));
                        isVisit[x][y - 1] = isVisit[x][y] + 1;
                    }
                    if (x + 1 < N && graph[x + 1][y] == 'L' && !isVisit[x + 1][y])
                    {
                        pairQ.push(make_pair(x + 1, y));
                        isVisit[x + 1][y] = isVisit[x][y] + 1;
                    }
                    if (y + 1 < M && graph[x][y + 1] == 'L' && !isVisit[x][y + 1])
                    {
                        pairQ.push(make_pair(x, y + 1));
                        isVisit[x][y + 1] = isVisit[x][y] + 1;
                    }
                }

                int distance = isVisit[lastX][lastY] - 1;
                if (distance > maxDistance)
                    maxDistance = distance;
                memset(isVisit, 0, sizeof(isVisit));
            }
        }
    }
    cout << maxDistance << endl;

    return 0;
}