/* 
ACMICPC 
문제 번호 : 2468
문제 제목 : 안전 영역
풀이 날짜 : 2020-05-02
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
using namespace std;

int graph[100][100] = {0};
bool isVisit[100][100] = {0};
int N;

void DFS(int x, int y, int height)
{
    isVisit[x][y] = true;

    if (x - 1 >= 0 && graph[x - 1][y] > height && !isVisit[x - 1][y])
        DFS(x - 1, y, height);
    if (x + 1 < N && graph[x + 1][y] > height && !isVisit[x + 1][y])
        DFS(x + 1, y, height);
    if (y - 1 >= 0 && graph[x][y - 1] > height && !isVisit[x][y - 1])
        DFS(x, y - 1, height);
    if (y + 1 < N && graph[x][y + 1] > height && !isVisit[x][y + 1])
        DFS(x, y + 1, height);
}

int main()
{
    int tmp;
    int maxHeight = 0;
    int maxArea = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            graph[i][j] = tmp;
            if (tmp > maxHeight)
                maxHeight = tmp;
        }
    }

    for (int i = 0; i < maxHeight; i++)
    {
        int area = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (graph[j][k] > i && !isVisit[j][k])
                {
                    area++;
                    DFS(j, k, i);
                }
            }
        }
        memset(isVisit, 0, sizeof(isVisit));
        if (area > maxArea)
            maxArea = area;
    }
    cout << maxArea << endl;
    return 0;
}