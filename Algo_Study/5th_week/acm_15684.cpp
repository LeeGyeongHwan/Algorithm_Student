/* 
ACMICPC
Study Group
5th Week
문제 번호 : 15684
문제 제목 : 사다리 조작
풀이 날짜 : 2020-09-01
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int ladder[31][11];
int tmpLadder[31][11];
int N, H;

bool isValid()
{
    for (int k = 1; k <= N; k++)
    {
        int idx = k;
        for (int i = 1; i <= H; i++)
        {
            if (idx - 1 >= 1 && tmpLadder[i][idx - 1] == 1)
                idx--;
            else if (tmpLadder[i][idx] == 1)
                idx++;
        }
        if (k != idx)
            return false;
    }
    return true;
}

bool addLine(int line, int total, int start)
{
    if (line == total)
    {
        if (isValid()) //정답
            return true;
        else
            return false;
        ;
    }

    for (int i = start; i < (N - 1) * H; i++)
    {
        int row = i / (N - 1) + 1;
        int col = i % (N - 1) + 1;

        if (tmpLadder[row][col] == 1 || (col - 1 >= 1 && ladder[row][col - 1] == 1) || (col + 1 <= N - 1 && ladder[row][col + 1] == 1))
            continue;

        tmpLadder[row][col] = 1;
        if (addLine(line + 1, total, i + 1))
            return true;
        tmpLadder[row][col] = 0;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    int a, b;
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        ladder[a][b] = tmpLadder[a][b] = 1;
    }

    //check하기
    int addedLine = 0;
    while (!isValid())
    {
        if (++addedLine > 3)
        {
            addedLine = -1;
            break;
        }
        //tmpLadder 초기화
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= H; j++)
                tmpLadder[i][j] = ladder[i][j];
        }
        //tmpLadder에 addLine개 사다리 추가하기
        if (addLine(0, addedLine, 0))
            break;
    }

    cout << addedLine << "\n";
    return 0;
}