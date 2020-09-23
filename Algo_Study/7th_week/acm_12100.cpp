/* 
ACMICPC
Study Group
7th Week
문제 번호 : 12100
문제 제목 : 2048 (Easy)
풀이 날짜 : 2020-09-23
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[20][20];
int tmpBoard[20][20];
int order[5];

int maxBlock = 0;

//밥 : 김취-> 쌓기
//계란밥

void playGame()
{
    for (int i = 0; i < 5; i++)
    {
        int dir = order[i];

        switch (dir)
        {
        case 0:
            for (int j = 0; j < N; j++)
            {
                //합치기
                int start = -1;
                for (int k = 0; k < N; k++)
                {
                    if (board[k][j] != 0)
                    {
                        if (start == -1)
                            start = k;
                        else
                        {
                            if (board[start][j] == board[k][j])
                            {
                                board[start][j] *= 2;
                                board[k][j] = 0;
                                start = -1;
                            }
                            else
                                start = k;
                        }
                    }
                }
                //땡기기
                int idx = -1;
                for (int k = 0; k < N; k++)
                {
                    if (board[k][j] == 0)
                    {
                        if (idx == -1)
                            idx = k;
                    }
                    else
                    {
                        if (idx != -1)
                        {
                            board[idx][j] = board[k][j];
                            board[k][j] = 0;
                            idx++;
                        }
                    }
                }
            }
            break;
        case 1:
            for (int j = 0; j < N; j++)
            {
                //합치기
                int start = -1;
                for (int k = 0; k < N; k++)
                {
                    if (board[j][k] != 0)
                    {
                        if (start == -1)
                            start = k;
                        else
                        {
                            if (board[j][start] == board[j][k])
                            {
                                board[j][start] *= 2;
                                board[j][k] = 0;
                                start = -1;
                            }
                            else
                                start = k;
                        }
                    }
                }
                //땡기기
                int idx = -1;
                for (int k = 0; k < N; k++)
                {
                    if (board[j][k] == 0)
                    {
                        if (idx == -1)
                            idx = k;
                    }
                    else
                    {
                        if (idx != -1)
                        {
                            board[j][idx] = board[j][k];
                            board[j][k] = 0;
                            idx++;
                        }
                    }
                }
            }
            break;
        case 2:
            for (int j = 0; j < N; j++)
            {
                //합치기
                int start = -1;
                for (int k = N - 1; k >= 0; k--)
                {
                    if (board[k][j] != 0)
                    {
                        if (start == -1)
                            start = k;
                        else
                        {
                            if (board[start][j] == board[k][j])
                            {
                                board[start][j] *= 2;
                                board[k][j] = 0;
                                start = -1;
                            }
                            else
                                start = k;
                        }
                    }
                }
                //땡기기
                int idx = -1;
                for (int k = N - 1; k >= 0; k--)
                {
                    if (board[k][j] == 0)
                    {
                        if (idx == -1)
                            idx = k;
                    }
                    else
                    {
                        if (idx != -1)
                        {
                            board[idx][j] = board[k][j];
                            board[k][j] = 0;
                            idx--;
                        }
                    }
                }
            }
            break;
        case 3:
            for (int j = 0; j < N; j++)
            {
                //합치기
                int start = -1;
                for (int k = N - 1; k >= 0; k--)
                {
                    if (board[j][k] != 0)
                    {
                        if (start == -1)
                            start = k;
                        else
                        {
                            if (board[j][start] == board[j][k])
                            {
                                board[j][start] *= 2;
                                board[j][k] = 0;
                                start = -1;
                            }
                            else
                                start = k;
                        }
                    }
                }
                //땡기기
                int idx = -1;
                for (int k = N - 1; k >= 0; k--)
                {
                    if (board[j][k] == 0)
                    {
                        if (idx == -1)
                            idx = k;
                    }
                    else
                    {
                        if (idx != -1)
                        {
                            board[j][idx] = board[j][k];
                            board[j][k] = 0;
                            idx--;
                        }
                    }
                }
            }
            break;
        }
    }

    //맥스 구하기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            maxBlock = maxBlock < board[i][j] ? board[i][j] : maxBlock;
}

void permutation(int cnt)
{
    if (cnt == 5)
    {
        copy(&board[0][0], &board[0][0] + 20 * 20, &tmpBoard[0][0]);
        playGame();
        copy(&tmpBoard[0][0], &tmpBoard[0][0] + 20 * 20, &board[0][0]);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        order[cnt] = i;
        permutation(cnt + 1);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    permutation(0);
    cout << maxBlock << endl;

    return 0;
}