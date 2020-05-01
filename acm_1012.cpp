/* 
ACMICPC 
문제 번호 : 1012
문제 제목 : 유기농 배추
풀이 날짜 : 2020-05-01
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
using namespace std;

bool graph[50][50] = {0};
bool isVisit[50][50] = {0};
int M, N;
void DFS(int x, int y)
{
    isVisit[x][y] = true;

    if (x - 1 >= 0 && !isVisit[x - 1][y] && graph[x - 1][y])
        DFS(x - 1, y);
    if (x + 1 < M && !isVisit[x + 1][y] && graph[x + 1][y])
        DFS(x + 1, y);
    if (y - 1 >= 0 && !isVisit[x][y - 1] && graph[x][y - 1])
        DFS(x, y - 1);
    if (y + 1 < N && !isVisit[x][y + 1] && graph[x][y + 1])
        DFS(x, y + 1);
}

int main()
{
    int testCase;
    int K;
    int x, y;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int testSum = 0;
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> x >> y;
            graph[x][y] = true;
        }

        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (graph[j][k] && !isVisit[j][k])
                {
                    testSum++;
                    DFS(j, k);
                }
            }
        }

        cout << testSum << endl;
        memset(graph, 0, sizeof(graph));
        memset(isVisit, 0, sizeof(isVisit));
    }

    return 0;
}
