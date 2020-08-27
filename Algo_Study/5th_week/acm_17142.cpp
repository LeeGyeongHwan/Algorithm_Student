/* 
ACMICPC
Study Group
5th Week
문제 번호 : 17142
문제 제목 : 연구소 3
풀이 날짜 : 2020-08-27
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int lab[50][50];
bool isVisited[50][50];
int N, M;
int emptySpace = 0;
vector<pair<int, int>> virusVec;
queue<tuple<int, int, int>> tupleQ;
int active[10];
int minTime = INT32_MAX;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N && !isVisited[x][y] && lab[x][y] != 1;
}

bool isFull()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (!(isVisited[i][j] || lab[i][j] == 1 || lab[i][j] == -1))
            {
                return false;
            }
    }
    return true;
}

void activateVirus()
{
    int tmpEmpty = emptySpace;
    memset(isVisited, 0, sizeof(isVisited));
    while (!tupleQ.empty())
    {
        tupleQ.pop();
    }

    //확산
    for (int i = 0; i < M; i++)
    {
        tupleQ.push({virusVec[active[i]].first, virusVec[active[i]].second, 0});
        isVisited[virusVec[active[i]].first][virusVec[active[i]].second] = true;
    }

    while (!tupleQ.empty())
    {
        int x, y, time;
        tie(x, y, time) = tupleQ.front();
        tupleQ.pop();

        if (time > minTime)
            return;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (!check(newX, newY))
                continue;
            isVisited[newX][newY] = true;
            tupleQ.push({newX, newY, time + 1});
            if (lab[newX][newY] == 0)
            {
                if (--tmpEmpty == 0)
                {
                    if (minTime > time + 1)
                        minTime = time + 1;
                    return;
                }
            }
        }
    }
}

void selectVirus(int cnt, int idx)
{
    if (cnt == M)
    {
        activateVirus();
        return;
    }

    for (int i = idx; i < virusVec.size(); i++)
    {
        active[cnt] = i;
        selectVirus(cnt + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            lab[i][j] = tmp;
            if (tmp == 2)
            {
                virusVec.push_back({i, j});
                lab[i][j] = -1;
            }
            else if (tmp == 0)
                emptySpace++;
        }
    }

    if (emptySpace == 0)
        minTime = 0;
    else
        selectVirus(0, 0);

    if (minTime == INT32_MAX)
        cout << "-1\n";
    else
        cout << minTime << "\n";

    return 0;
}