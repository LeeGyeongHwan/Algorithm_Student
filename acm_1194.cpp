/* 
ACMICPC 
문제 번호 : 1194 
문제 제목 : 달이 차오른다, 가자.
풀이 날짜 : 2020-10-30
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

char maze[50][50];
int isVisited[50][50][64];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
pair<int, int> minsik;
queue<tuple<int, int, int, int>> tupleQ;
int answer = INT32_MAX;

int main()
{
    string str;
    cin >> N >> M;

    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 64; k++)
                isVisited[i][j][k] = INT32_MAX;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = str[j];
            if (str[j] == '0')
                minsik = {i, j};
        }
    }
    int x, y, dist, key;

    tupleQ.push({minsik.first, minsik.second, 0, 0});
    isVisited[minsik.first][minsik.second][0] = 0;

    while (!tupleQ.empty())
    {
        tie(x, y, dist, key) = tupleQ.front();
        tupleQ.pop();
        if (dist > answer)
            continue;
        if (maze[x][y] == '1')
        {
            if (answer > dist)
                answer = dist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= N || newY < 0 || newY >= M || isVisited[newX][newY][key] <= dist + 1)
                continue;
            if (maze[newX][newY] == '#')
                continue;
            if (maze[newX][newY] >= 'a' && maze[newX][newY] <= 'f')
            {
                int tmpKey = (int)maze[newX][newY] - 'a';
                isVisited[newX][newY][(key | (1 << tmpKey))] = dist + 1;
                tupleQ.push({newX, newY, dist + 1, (key | (1 << tmpKey))});
            }
            else if (maze[newX][newY] >= 'A' && maze[newX][newY] <= 'F')
            {
                int tmpKey = (int)maze[newX][newY] - 'A';

                if ((key & (1 << tmpKey)) > 0)
                {
                    isVisited[newX][newY][key] = dist + 1;
                    tupleQ.push({newX, newY, dist + 1, key});
                }
            }
            else
            {
                isVisited[newX][newY][key] = dist + 1;
                tupleQ.push({newX, newY, dist + 1, key});
            }
        }
    }

    if (answer == INT32_MAX)
        answer = -1;
    cout << answer << "\n";

    return 0;
}