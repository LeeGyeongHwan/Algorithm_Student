/*
ACMICPC
문제 번호 : 2206
문제 제목 : 벽 부수고 이동하기
풀이 날짜 : 2020-08-04
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

bool map[1000][1000] = {0};
int isVisited[1000][1000][2] = {0};
int x, y, z;
int newX, newY;
queue<tuple<int, int, int>> tupleQ;

int main()
{
    int N, M;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    string str;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            if (str[j] == '1')
                map[i][j] = true;
        }
    }

    tupleQ.push(make_tuple(0, 0, 1));
    isVisited[0][0][1] = 1;
    int isAnswer = 0;

    while (!tupleQ.empty())
    {

        tie(x, y, z) = tupleQ.front();
        tupleQ.pop();
        if (x == N - 1 && y == M - 1)
        {
            isAnswer = 1;
            if (z == 1)
            {
                isAnswer = 2;
            }
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            newX = x + dx[i];
            newY = y + dy[i];
            if (newX >= 0 && newX < N && newY >= 0 && newY < M)
            {

                if (map[newX][newY] && z == 1)
                {
                    isVisited[newX][newY][0] = isVisited[x][y][1] + 1;
                    tupleQ.push(make_tuple(newX, newY, 0));
                    continue;
                }
                if (!map[newX][newY] && !isVisited[newX][newY][z])
                {
                    isVisited[newX][newY][z] = isVisited[x][y][z] + 1;
                    tupleQ.push(make_tuple(newX, newY, z));
                }
            }
        }
    }

    if (isAnswer == 2)
        cout << isVisited[N - 1][M - 1][1] << endl;
    else if (isAnswer == 1)
        cout << isVisited[N - 1][M - 1][0] << endl;
    else
        cout << "-1" << endl;

    return 0;
}