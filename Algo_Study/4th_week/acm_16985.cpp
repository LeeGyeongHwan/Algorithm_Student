/* 
ACMICPC
Study Group
4th Week
문제 번호 : 16985
문제 제목 : Maaaaaaaaaze
풀이 날짜 : 2020-08-23
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>
#include <queue>
using namespace std;

int maze[5][5][5];
int tmpMaze[5][5][5];

queue<tuple<int, int, int, int>> tupleQ;
bool isVisited[5][5][5];

vector<int> vecLayer;
bool selectedLayer[5];

vector<int> vecRotate;

int startZ[] = {0, 0, 0, 0, 4, 4, 4, 4};
int startX[] = {0, 0, 4, 4, 0, 0, 4, 4};
int startY[] = {0, 4, 0, 4, 0, 4, 0, 4};

int dz[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, 0, -1, 0};
int dy[] = {0, 0, 0, 1, 0, -1};

int minMove = INT32_MAX;

bool check(int z, int x, int y)
{
    if (z >= 0 && z < 5 && x >= 0 && x < 5 && y >= 0 && y < 5 && !isVisited[z][x][y] && tmpMaze[z][x][y] == 1)
        return true;
    return false;
}

void escape()
{
    int z, x, y;
    int tmpZ, tmpX, tmpY, move;

    for (int i = 0; i < 8; i++)
    {

        z = startZ[i];
        x = startX[i];
        y = startY[i];

        if (tmpMaze[z][x][y] == 0)
            continue;
        memset(isVisited, 0, sizeof(isVisited));
        while (!tupleQ.empty())
        {
            tupleQ.pop();
        }

        tupleQ.push({z, x, y, 0});
        isVisited[z][x][y] = true;
        int tmpMove = INT32_MAX;
        while (!tupleQ.empty())
        {
            tie(tmpZ, tmpX, tmpY, move) = tupleQ.front();
            tupleQ.pop();

            if (tmpZ == 4 - z && tmpX == 4 - x && tmpY == 4 - y)
            {
                tmpMove = move;
                break;
            }

            for (int j = 0; j < 6; j++)
            {
                int newZ = tmpZ + dz[j];
                int newX = tmpX + dx[j];
                int newY = tmpY + dy[j];

                if (!check(newZ, newX, newY))
                    continue;

                isVisited[newZ][newX][newY] = true;
                tupleQ.push({newZ, newX, newY, move + 1});
            }
        }
        if (tmpMove < minMove)
            minMove = tmpMove;
    }
}

void makeMaze()
{
    for (int i = 0; i < 5; i++)
    {
        int rotate;
        if (i == 0)
            rotate = 0;
        else
            rotate = vecRotate[i - 1];
        int layer = vecLayer[i];
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                switch (rotate)
                {
                case 0:
                    tmpMaze[i][j][k] = maze[layer][j][k];
                    break;
                case 1:
                    tmpMaze[i][j][k] = maze[layer][4 - k][j];
                    break;
                case 2:
                    tmpMaze[i][j][k] = maze[layer][4 - j][4 - k];
                    break;
                case 3:
                    tmpMaze[i][j][k] = maze[layer][k][4 - j];
                    break;
                }
            }
        }
    }
}

void combRotate(int cnt)
{
    if (cnt == 4)
    {
        // for (int i = 0; i < 4; i++)
        //     cout << vecRotate[i] << " ";
        // cout << endl;
        makeMaze();
        escape();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vecRotate.push_back(i);
        combRotate(cnt + 1);
        vecRotate.pop_back();
    }
}

void permuLayer(int cnt)
{
    if (cnt == 5)
    {
        combRotate(0);
        // for (int i = 0; i < 5; i++)
        //     cout << vecLayer[i] << " ";
        // cout << endl;
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (selectedLayer[i])
            continue;

        selectedLayer[i] = true;
        vecLayer.push_back(i);
        permuLayer(cnt + 1);
        selectedLayer[i] = false;
        vecLayer.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> maze[i][j][k];
            }
        }
    }

    permuLayer(0);

    if (minMove == INT32_MAX)
        cout << "-1\n";
    else
        cout << minMove << "\n";

    return 0;
}