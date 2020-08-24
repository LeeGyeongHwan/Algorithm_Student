/* 
ACMICPC
Study Group
4th Week
문제 번호 : 1600
문제 제목 : 말이 되고픈 원숭이
풀이 날짜 : 2020-08-25
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[200][200];

int horseX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horseY[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isVisited[200][200][31];
int W, H;

queue<tuple<int, int, int, int>> tupleQ;
bool check(int x, int y, int move)
{
    if (x >= 0 && x < H && y >= 0 && y < W && !isVisited[x][y][move] && board[x][y] == 0)
        return true;
    return false;
}

int main()
{
    int K;
    int x, y, horse, move;
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }

    tupleQ.push({0, 0, K, 0});
    isVisited[0][0][K] = true;
    int minMove = -1;
    while (!tupleQ.empty())
    {
        tie(x, y, horse, move) = tupleQ.front();
        tupleQ.pop();

        if (x == H - 1 && y == W - 1)
        {
            minMove = move;
            break;
        }

        if (horse != 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int newX = x + horseX[i];
                int newY = y + horseY[i];
                if (!check(newX, newY, horse - 1))
                    continue;
                isVisited[newX][newY][horse - 1] = true;
                tupleQ.push({newX, newY, horse - 1, move + 1});
            }
        }

        for (int i = 0; i < 4; i++)
        {

            int newX = x + dx[i];
            int newY = y + dy[i];
            if (!check(newX, newY, horse))
                continue;
            isVisited[newX][newY][horse] = true;
            tupleQ.push({newX, newY, horse, move + 1});
        }
    }

    cout << minMove << "\n";

    return 0;
}