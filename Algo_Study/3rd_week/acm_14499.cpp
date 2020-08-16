/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 14499
문제 제목 : 주사위 굴리기
풀이 날짜 : 2020-08-16
Solved By Reamer 
*/

#include <iostream>
using namespace std;

int dx[] = {0, 0, -1, 1}; //동,서,북,남
int dy[] = {1, -1, 0, 0};
int dice[4][3] = {{0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0}};

void rollDice(int direction)
{
    if (direction == 0)
    {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = tmp;
    }
    else if (direction == 1)
    {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = tmp;
    }
    else if (direction == 2)
    {
        int tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
    }
    else if (direction == 3)
    {
        int tmp = dice[0][1];
        dice[0][1] = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int map[20][20] = {0};
    int N, M, x, y, op, move;
    cin >> N >> M >> x >> y >> op;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < op; i++)
    {
        cin >> move;
        int newX = x + dx[move - 1];
        int newY = y + dy[move - 1];
        if (newX >= 0 && newX < N && newY >= 0 && newY < M)
        {
            //주사위 이동
            rollDice(move - 1);
            x = newX;
            y = newY;
            //복사 작업
            //0 : 주사위->맵 , other : 맵->주사위
            if (map[newX][newY] == 0)
                map[newX][newY] = dice[3][1];
            else
            {
                dice[3][1] = map[newX][newY];
                map[newX][newY] = 0;
            }

            cout << dice[1][1] << "\n";
        }
    }

    return 0;
}