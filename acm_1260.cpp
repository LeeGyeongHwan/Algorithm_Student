/* 
ACMICPC 
문제 번호 : 1260
문제 제목 : DFS와 BFS
풀이 날짜 : 2020-05-01
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
#include <queue>

int graph[1001][1001] = {0};
bool isVisit[1001] = {0};

using namespace std;

void DFS(int N, int V, int depth)
{
    isVisit[V] = true;
    if (depth != N)
    {
        cout << V << " ";
    }

    for (int i = 1; i <= N; i++)
    {
        if (graph[V][i] == 1 && !isVisit[i])
        {
            DFS(N, i, depth + 1);
        }
    }
}

int main()
{
    int N, M, V;
    int x, y;

    queue<int> bfsQ;
    vector<int> bfsVec;

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(N, V, 0);
    cout << endl;

    memset(isVisit, 0, sizeof(isVisit));
    bfsQ.push(V);
    isVisit[V] = true;
    while (!bfsQ.empty())
    {
        int vertex = bfsQ.front();
        bfsQ.pop();
        bfsVec.push_back(vertex);
        for (int i = 1; i <= N; i++)
        {
            if (graph[vertex][i] == 1 && !isVisit[i])
            {
                bfsQ.push(i);
                graph[vertex][i] = 2;
                graph[i][vertex] = 2;
                isVisit[i] = true;
            }
        }
    }

    for (int i = 0; i < bfsVec.size(); i++)
        cout << bfsVec[i] << " ";

    return 0;
}