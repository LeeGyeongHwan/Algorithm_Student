/* 
ACMICPC
Study Group
9th Week
문제 번호 : 2234
문제 제목 : 성곽 
풀이 날짜 : 2020-10-01
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int map[50][50];
    int roomNum[50][50];
    int roomArr[2500];
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int cntRoom = 0;
    int maxRoom = 0;
    int maxAfterBreak = 0;
    int x, y, wall;
    bool isVisited[50][50];
    queue<tuple<int, int, int>> tupleQ;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j])
            {
                tupleQ.push({i, j, 1});
                isVisited[i][j] = true;
                int roomSize = 0;
                while (!tupleQ.empty())
                {
                    tie(x, y, wall) = tupleQ.front();
                    roomNum[x][y] = cntRoom;
                    roomSize++;
                    tupleQ.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if ((map[x][y] & (1 << k)) != 0) //벽
                            continue;
                        int newX = x + dx[k];
                        int newY = y + dy[k];
                        if (newX < 0 || newX >= m || newY < 0 || newY >= n || isVisited[newX][newY])
                            continue;
                        isVisited[newX][newY] = true;
                        tupleQ.push({newX, newY, 1});
                    }
                }
                roomArr[cntRoom++] = roomSize;
                maxRoom = maxRoom > roomSize ? maxRoom : roomSize;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = roomNum[i][j];
            for (int k = 0; k < 4; k++)
            {
                int newX = i + dx[k];
                int newY = j + dy[k];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;
                if (num != roomNum[newX][newY])
                {
                    int sumRoom = roomArr[num] + roomArr[roomNum[newX][newY]];
                    maxAfterBreak = maxAfterBreak > sumRoom ? maxAfterBreak : sumRoom;
                }
            }
        }
    }
    cout << cntRoom << "\n"
         << maxRoom << "\n"
         << maxAfterBreak << "\n";

    return 0;
}