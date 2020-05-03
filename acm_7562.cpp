/* 
ACMICPC 
문제 번호 : 7562
문제 제목 : 나이트의 이동
풀이 날짜 : 2020-05-03
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int graph[300][300] = {0};
bool isVisit[300][300] = {0};

int main()
{
    int testCase, size;
    int xNight, yNight;
    int xDest, yDest;
    queue<pair<int, int>> pairQ;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> size;
        cin >> xNight >> yNight;
        cin >> xDest >> yDest;
        graph[xNight][yNight] = 1;
        isVisit[xNight][yNight] = true;
        pairQ.push(make_pair(xNight, yNight));

        while (!pairQ.empty())
        {
            int x = pairQ.front().first;
            int y = pairQ.front().second;
            pairQ.pop();

            if (x == xDest && y == yDest)
                break;

            if (x - 2 >= 0 && y - 1 >= 0 && !isVisit[x - 2][y - 1])
            {
                pairQ.push(make_pair(x - 2, y - 1));
                isVisit[x - 2][y - 1] = true;
                graph[x - 2][y - 1] = graph[x][y] + 1;
            }
            if (x - 1 >= 0 && y - 2 >= 0 && !isVisit[x - 1][y - 2])
            {
                pairQ.push(make_pair(x - 1, y - 2));
                isVisit[x - 1][y - 2] = true;
                graph[x - 1][y - 2] = graph[x][y] + 1;
            }
            if (x + 1 < size && y - 2 >= 0 && !isVisit[x + 1][y - 2])
            {
                pairQ.push(make_pair(x + 1, y - 2));
                isVisit[x + 1][y - 2] = true;
                graph[x + 1][y - 2] = graph[x][y] + 1;
            }
            if (x + 2 < size && y - 1 >= 0 && !isVisit[x + 2][y - 1])
            {
                pairQ.push(make_pair(x + 2, y - 1));
                isVisit[x + 2][y - 1] = true;
                graph[x + 2][y - 1] = graph[x][y] + 1;
            }
            if (x - 2 >= 0 && y + 1 < size && !isVisit[x - 2][y + 1])
            {
                pairQ.push(make_pair(x - 2, y + 1));
                isVisit[x - 2][y + 1] = true;
                graph[x - 2][y + 1] = graph[x][y] + 1;
            }
            if (x - 1 >= 0 && y + 2 < size && !isVisit[x - 1][y + 2])
            {
                pairQ.push(make_pair(x - 1, y + 2));
                isVisit[x - 1][y + 2] = true;
                graph[x - 1][y + 2] = graph[x][y] + 1;
            }
            if (x + 1 < size && y + 2 < size && !isVisit[x + 1][y + 2])
            {
                pairQ.push(make_pair(x + 1, y + 2));
                isVisit[x + 1][y + 2] = true;
                graph[x + 1][y + 2] = graph[x][y] + 1;
            }
            if (x + 2 < size && y + 1 < size && !isVisit[x + 2][y + 1])
            {
                pairQ.push(make_pair(x + 2, y + 1));
                isVisit[x + 2][y + 1] = true;
                graph[x + 2][y + 1] = graph[x][y] + 1;
            }
        }

        cout << graph[xDest][yDest] - 1 << endl;
        memset(isVisit, 0, sizeof(isVisit));
        while (!pairQ.empty())
        {
            pairQ.pop();
        }
    }
    return 0;
}