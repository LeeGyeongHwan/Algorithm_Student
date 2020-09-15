/* 
ACMICPC
Study Group
6th Week
문제 번호 : 18808
문제 제목 : 스티커 붙이기
풀이 날짜 : 2020-09-16
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>> intVec[100];
vector<pair<int, int>> pairVec;
int board[40][40];

void putSticker(int idx, int x, int y, int mode, int dir)
{
    int r, c;
    if (dir % 2 == 0)
        tie(r, c) = pairVec[idx];
    else
        tie(c, r) = pairVec[idx];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            switch (dir)
            {
            case 0:
                board[x + i][y + j] += intVec[idx][i][j] * mode;
                break;
            case 1:
                board[x + i][y + j] += intVec[idx][c - j - 1][i] * mode;
                break;
            case 2:
                board[x + i][y + j] += intVec[idx][r - i - 1][c - j - 1] * mode;
                break;
            case 3:
                board[x + i][y + j] += intVec[idx][j][r - i - 1] * mode;
                break;
            default:
                break;
            }
        }
    }
}

bool checkOverlap(int idx, int x, int y, int dir)
{
    int r, c;
    if (dir % 2 == 0)
        tie(r, c) = pairVec[idx];
    else
        tie(c, r) = pairVec[idx];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[x + i][y + j] > 1)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> tmpVec;
    int N, M, K;
    int R, C, tmp;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> R >> C;
        pairVec.push_back({R, C});
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVec[i].push_back(tmpVec);
            tmpVec.clear();
        }
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 4; j++) //0,90,180,270회전
        {
            if (j % 2 == 0)
                tie(R, C) = pairVec[i];
            else
                tie(C, R) = pairVec[i];
            bool oob = false;
            bool canPut = false;
            for (int x = 0; x <= N - R; x++)
            {
                for (int y = 0; y <= M - C; y++)
                {
                    if (x + R > N || y + C > M)
                    {
                        oob = true;
                        break;
                    }
                    putSticker(i, x, y, 1, j);

                    if (checkOverlap(i, x, y, j))
                    {
                        putSticker(i, x, y, -1, j);
                    }
                    else
                    {
                        canPut = true;
                        break;
                    }
                }
                if (oob || canPut)
                    break;
            }
            if (canPut)
                break;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if (board[i][j] == 1)
                sum++;
    }
    cout << sum << "\n";
    return 0;
}