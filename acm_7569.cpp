/* 
ACMICPC 
문제 번호 : 7569
문제 제목 : 토마토
풀이 날짜 : 2020-05-02
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int graph[100][100][100] = {0};
bool isVisit[100][100][100] = {0};
int main()
{
    int M, N, H, tmp;
    queue<tuple<int, int, int>> tupleQ;

    int maxDay = 0;
    bool isCan = true;

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> tmp;
                graph[i][j][k] = tmp;
                if (tmp == 1)
                {
                    tupleQ.push(make_tuple(i, j, k));
                    isVisit[i][j][k] = true;
                }
            }
        }
    }

    while (!tupleQ.empty())
    {
        int x, y, z;

        tie(z, x, y) = tupleQ.front();
        tupleQ.pop();

        if (x - 1 >= 0 && graph[z][x - 1][y] == 0 && !isVisit[z][x - 1][y])
        {
            tupleQ.push(make_tuple(z, x - 1, y));
            isVisit[z][x - 1][y] = true;
            graph[z][x - 1][y] = graph[z][x][y] + 1;
        }
        if (x + 1 < N && graph[z][x + 1][y] == 0 && !isVisit[z][x + 1][y])
        {
            tupleQ.push(make_tuple(z, x + 1, y));
            isVisit[z][x + 1][y] = true;
            graph[z][x + 1][y] = graph[z][x][y] + 1;
        }
        if (y - 1 >= 0 && graph[z][x][y - 1] == 0 && !isVisit[z][x][y - 1])
        {
            tupleQ.push(make_tuple(z, x, y - 1));
            isVisit[z][x][y - 1] = true;
            graph[z][x][y - 1] = graph[z][x][y] + 1;
        }
        if (y + 1 < M && graph[z][x][y + 1] == 0 && !isVisit[z][x][y + 1])
        {
            tupleQ.push(make_tuple(z, x, y + 1));
            isVisit[z][x][y + 1] = true;
            graph[z][x][y + 1] = graph[z][x][y] + 1;
        }
        if (z - 1 >= 0 && graph[z - 1][x][y] == 0 && !isVisit[z - 1][x][y])
        {
            tupleQ.push(make_tuple(z - 1, x, y));
            isVisit[z - 1][x][y] = true;
            graph[z - 1][x][y] = graph[z][x][y] + 1;
        }
        if (z + 1 < H && graph[z + 1][x][y] == 0 && !isVisit[z + 1][x][y])
        {
            tupleQ.push(make_tuple(z + 1, x, y));
            isVisit[z + 1][x][y] = true;
            graph[z + 1][x][y] = graph[z][x][y] + 1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (graph[i][j][k] == 0)
                {
                    isCan = false;
                    break;
                }
                if (graph[i][j][k] > maxDay)
                    maxDay = graph[i][j][k];
            }
        }
    }

    if (isCan)
        cout << maxDay - 1 << endl;
    else
        cout << "-1" << endl;
    return 0;
}