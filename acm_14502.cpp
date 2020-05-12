/* 
ACMICPC 
문제 번호 : 14502
문제 제목 : 연구소
풀이 날짜 : 2020-05-12
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
using namespace std;

int N, M;
int graph[8][8] = {0};
int tmpGraph[8][8] = {0};
int maxArea = 0;
int wayX[] = {0, 1, 0, -1};
int wayY[] = {1, 0, -1, 0};
bool isVisit[8][8] = {0};

void DFS2(int x, int y)
{
    isVisit[x][y] = true;
    tmpGraph[x][y] = 2;

    for (int i = 0; i < 4; i++)
    {
        int tmpX = x + wayX[i];
        int tmpY = y + wayY[i];

        if (!(tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < M))
            continue;

        if (!isVisit[tmpX][tmpY] && tmpGraph[tmpX][tmpY] == 0)
            DFS2(tmpX, tmpY);
    }
}

int DFS0(int x, int y)
{
    int num = 1;
    isVisit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int tmpX = x + wayX[i];
        int tmpY = y + wayY[i];

        if (!(tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < M))
            continue;

        if (!isVisit[tmpX][tmpY] && tmpGraph[tmpX][tmpY] == 0)
            num += DFS0(tmpX, tmpY);
    }
    return num;
}

void constructWall(int x, int y, int wall)
{

    if (wall == 3)
    {
        memset(tmpGraph, 0, sizeof(tmpGraph));
        copy(&graph[0][0], &graph[0][0] + 8 * 8, &tmpGraph[0][0]);
        memset(isVisit, 0, sizeof(isVisit));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tmpGraph[i][j] == 2 && !isVisit[i][j])
                {
                    DFS2(i, j);
                }
            }
        }
        int area = 0;
        memset(isVisit, 0, sizeof(isVisit));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tmpGraph[i][j] == 0 && !isVisit[i][j])
                {
                    area += DFS0(i, j);
                }
            }
        }

        if (maxArea < area)
        {
            maxArea = area;
        }
        return;
    }

    for (int j = y; j < M; j++)
    {
        if (graph[x][j] == 0)
        {
            graph[x][j] = 1;
            constructWall(x, j, wall + 1);
            graph[x][j] = 0;
        }
    }
    for (int i = x + 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                constructWall(i, j, wall + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    int tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    constructWall(0, 0, 0);

    cout << maxArea << endl;

    return 0;
}