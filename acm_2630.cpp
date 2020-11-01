/* 
ACMICPC 
문제 번호 : 2630 
문제 제목 : 색종이 만들기
풀이 날짜 : 2020-11-01
Solved By Reamer 
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int paper[128][128];
int white, blue;

void findBlue(int x, int y, int N)
{
    if (N == 0)
        return;

    int whiteCnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (paper[x + i][y + j] == 0)
                whiteCnt++;

    if (whiteCnt == N * N)
        white++;
    else if (whiteCnt == 0)
        blue++;
    else
    {
        findBlue(x, y, N / 2);
        findBlue(x + N / 2, y, N / 2);
        findBlue(x, y + N / 2, N / 2);
        findBlue(x + N / 2, y + N / 2, N / 2);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    findBlue(0, 0, N);
    cout << white << "\n"
         << blue << "\n";

    return 0;
}