/* 
ACMICPC 
문제 번호 : 2636
문제 제목 : 치즈
풀이 날짜 : 2020-05-19
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

int graph[100][100] = {0};
bool isVisit[100][100] = {0};

int main()
{
    int N, M, tmp;
    int count = 0;
    int cheeze = 0;
    int tmpCheeze;
    queue<pair<int, int>> pairQ;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            graph[i][j] = tmp;
            if (tmp == 1)
                cheeze++;
        }
    }
    tmpCheeze = cheeze;
    while (cheeze != 0)
    {
        count++;
        tmpCheeze = cheeze;
        pairQ.push(make_pair(0, 0));
        isVisit[0][0] = true;
        while (!pairQ.empty())
        {
            int x, y;
            tie(x, y) = pairQ.front();
            pairQ.pop();
            if (x - 1 >= 0 && !isVisit[x - 1][y])
            {
                if (graph[x - 1][y] == 1)
                {
                    graph[x - 1][y] = 0;
                    isVisit[x - 1][y] = true;
                    cheeze--;
                }
                else
                {
                    isVisit[x - 1][y] = true;
                    pairQ.push(make_pair(x - 1, y));
                }
            }
            if (y - 1 >= 0 && !isVisit[x][y - 1])
            {
                if (graph[x][y - 1] == 1)
                {
                    graph[x][y - 1] = 0;
                    isVisit[x][y - 1] = true;
                    cheeze--;
                }
                else
                {
                    isVisit[x][y - 1] = true;
                    pairQ.push(make_pair(x, y - 1));
                }
            }
            if (x + 1 < N && !isVisit[x + 1][y])
            {
                if (graph[x + 1][y] == 1)
                {
                    graph[x + 1][y] = 0;
                    isVisit[x + 1][y] = true;
                    cheeze--;
                }
                else
                {
                    isVisit[x + 1][y] = true;
                    pairQ.push(make_pair(x + 1, y));
                }
            }
            if (y + 1 < M && !isVisit[x][y + 1])
            {
                if (graph[x][y + 1] == 1)
                {
                    graph[x][y + 1] = 0;
                    isVisit[x][y + 1] = true;
                    cheeze--;
                }
                else
                {
                    isVisit[x][y + 1] = true;
                    pairQ.push(make_pair(x, y + 1));
                }
            }
        }
        memset(isVisit, 0, sizeof(isVisit));
    }

    cout << count << "\n"
         << tmpCheeze << endl;

    return 0;
}
