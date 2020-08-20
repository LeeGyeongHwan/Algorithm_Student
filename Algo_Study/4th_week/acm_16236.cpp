/* 
ACMICPC
Study Group
4th Week
문제 번호 : 16236
문제 제목 : 아기 상어
풀이 날짜 : 2020-08-20
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int sea[20][20];
queue<tuple<int, int, int>> tupleQ;
pair<int, int> shark;
int N;
int sharkSize = 2;
int fishCnt = 0;
int time = 0;

int dx[] = {-1, 0, 1, 0}; //상좌하우
int dy[] = {0, -1, 0, 1};
bool isVisited[20][20] = {0};

void feeding()
{
    tupleQ.push({shark.first, shark.second, 0});
    isVisited[shark.first][shark.second] = true;
    memset(isVisited, 0, sizeof(isVisited));
    pair<int, int> tmpLoc;
    int minDist = 400;
    bool isFind = false;
    while (!tupleQ.empty())
    {
        int x, y, dist;
        tie(x, y, dist) = tupleQ.front();
        tupleQ.pop();

        if (sea[x][y] != 0 && sea[x][y] < sharkSize)
        {

            isFind = true;
            if (minDist > dist)
            {
                minDist = dist;
                tmpLoc = {x, y};
            }
            else if (minDist == dist)
            {
                if (minDist == dist)
                {
                    if (x < tmpLoc.first)
                        tmpLoc = {x, y};
                    else if (x == tmpLoc.first && y < tmpLoc.second)
                        tmpLoc = {x, y};
                }
            }
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= N || newY < 0 || newY >= N)
                continue;
            if (sea[newX][newY] > sharkSize || isVisited[newX][newY])
                continue;

            isVisited[newX][newY] = true;
            tupleQ.push({newX, newY, dist + 1});
        }
    }

    if (isFind)
    {
        if (sharkSize < 7)
        {
            fishCnt++;
            if (fishCnt == sharkSize)
            {
                sharkSize++;
                fishCnt = 0;
            }
        }

        shark = tmpLoc;
        sea[shark.first][shark.second] = 0;
        time += minDist;
        feeding();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            sea[i][j] = tmp;
            if (tmp == 9)
            {
                shark = {i, j};
                sea[i][j] = 0;
            }
        }
    }
    feeding();
    cout << time << "\n";

    return 0;
}