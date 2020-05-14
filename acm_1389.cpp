/* 
ACMICPC 
문제 번호 : 1389
문제 제목 : 케빈 베이컨의 6단계 법칙
풀이 날짜 : 2020-05-14
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

int graph[101][101] = {0};
bool isVisit[101] = {0};

int main()
{
    int N, M;
    int x, y;
    queue<int> intQ;
    cin >> N >> M;
    pair<int, int> minNum = make_pair(INT32_MAX, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        int number = 0;
        graph[i][i] = 1;
        isVisit[i] = true;
        intQ.push(i);

        while (!intQ.empty())
        {
            int tmp = intQ.front();
            intQ.pop();
            for (int j = 1; j <= N; j++)
            {
                if (graph[tmp][j] != 0 && !isVisit[j])
                {
                    graph[j][j] = graph[tmp][tmp] + 1;
                    isVisit[j] = true;
                    intQ.push(j);
                }
            }
        }
        for (int j = 1; j <= N; j++)
        {
            int distance = graph[j][j];
            graph[j][j] = 0;
            if (i == j)
                continue;
            number += distance;
        }

        if (number < minNum.first)
            minNum = make_pair(number, i);
        memset(isVisit, 0, sizeof(isVisit));
    }
    cout << minNum.second << endl;

    return 0;
}