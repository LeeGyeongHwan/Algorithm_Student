/* 
ACMICPC
Study Group
9th Week
문제 번호 : 19236
문제 제목 : 청소년 상어
풀이 날짜 : 2020-10-05
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int map[4][4];
int fishLoc[17][2];

int maxNum = 0;

void moveShark(int sx, int sy, int sumFish)
{
    int deadFishNum = map[sx][sy] / 10;
    int deadFishDir = map[sx][sy] % 10 - 1;

    map[sx][sy] = 0;
    fishLoc[deadFishNum][0] = -1;

    if (sumFish + deadFishNum > maxNum)
        maxNum = sumFish + deadFishNum;

    //fish move
    for (int i = 1; i <= 16; i++)
    {
        if (fishLoc[i][0] == -1) //deadFish
            continue;

        int fx = fishLoc[i][0];
        int fy = fishLoc[i][1];
        int dir = map[fx][fy] % 10 - 1;
        for (int j = 0; j < 8; j++)
        {
            int newX = fx + dx[dir];
            int newY = fy + dy[dir];
            if (newX < 0 || newX >= 4 || newY < 0 || newY >= 4 || (newX == sx && newY == sy))
            {
                dir = (dir + 1) % 8;
                continue;
            }
            //갈수있음
            if (map[newX][newY] == 0) //혼자만간다.
            {
                map[newX][newY] = i * 10 + (dir + 1);
                fishLoc[i][0] = newX;
                fishLoc[i][1] = newY;
                map[fx][fy] = 0;
            }
            else
            {
                int tmp = map[newX][newY];
                map[newX][newY] = i * 10 + (dir + 1);
                fishLoc[i][0] = newX;
                fishLoc[i][1] = newY;
                //swap
                map[fx][fy] = tmp;
                int tmpNum = tmp / 10;
                fishLoc[tmpNum][0] = fx;
                fishLoc[tmpNum][1] = fy;
            }
            break;
        }
    }
    //shark move

    int tmpMap[4][4];
    int tmpLoc[17][2];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmpMap[i][j] = map[i][j];
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 2; j++)
            tmpLoc[i][j] = fishLoc[i][j];

    int tmpX = sx;
    int tmpY = sy;

    while (true)
    {
        tmpX += dx[deadFishDir];
        tmpY += dy[deadFishDir];

        if (tmpX < 0 || tmpX >= 4 || tmpY < 0 || tmpY >= 4)
            break;
        if (map[tmpX][tmpY] == 0)
            continue;

        moveShark(tmpX, tmpY, sumFish + deadFishNum);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                map[i][j] = tmpMap[i][j];
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 2; j++)
                fishLoc[i][j] = tmpLoc[i][j];
    }
}

int main()
{
    int fish, dir;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> fish >> dir;
            map[i][j] = fish * 10 + dir;
            fishLoc[fish][0] = i;
            fishLoc[fish][1] = j;
        }
    }

    moveShark(0, 0, 0);
    cout << maxNum << endl;
    return 0;
}