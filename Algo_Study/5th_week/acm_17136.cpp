/* 
ACMICPC
Study Group
5th Week
문제 번호 : 17136
문제 제목 : 색종이 붙이기
풀이 날짜 : 2020-09-03
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int cPaper[10][10];
int numPaper[5] = {5, 5, 5, 5, 5};
int minPaper = INT32_MAX;

bool check(int x, int y, int size)
{
    if (x + size >= 10 || y + size >= 10)
        return false;
    for (int i = x; i <= x + size; i++)
    {
        for (int j = y; j <= y + size; j++)
        {
            if (cPaper[i][j] == 0)
                return false;
        }
    }
    return true;
}

void modifyPaper(int x, int y, int size, int mode)
{
    for (int i = x; i <= x + size; i++)
    {
        for (int j = y; j <= y + size; j++)
        {
            cPaper[i][j] = mode;
        }
    }
}

void deployPaper(int idx)
{
    if (idx == 100)
    {
        int usedPaper = 25;
        for (int i = 0; i < 5; i++)
            usedPaper -= numPaper[i];
        if (minPaper > usedPaper)
            minPaper = usedPaper;
        return;
    }

    int x = idx / 10;
    int y = idx % 10;
    if (cPaper[x][y] == 0)
    {
        deployPaper(idx + 1);
        return;
    }

    for (int size = 4; size >= 0; size--)
    {
        if (numPaper[size] == 0 || !check(x, y, size))
            continue;

        modifyPaper(x, y, size, 0);
        numPaper[size]--;
        deployPaper(idx + size + 1);
        modifyPaper(x, y, size, 1);
        numPaper[size]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> cPaper[i][j];
        }
    }

    //색종이 배치
    deployPaper(0);

    if (minPaper == INT32_MAX)
        cout << "-1\n";
    else
        cout << minPaper << "\n";

    return 0;
}