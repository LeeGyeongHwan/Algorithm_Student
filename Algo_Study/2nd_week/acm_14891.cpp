/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 14891
문제 제목 : 톱니바퀴
풀이 날짜 : 2020-08-06
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int gear[4][8];
bool touch[4];

void rotation(int num, int dir, int mode)
{
    if (num < 1 || num > 4) //num의 범위
        return;

    if (dir == 1)
    {
        int tmp = gear[num - 1][7];
        for (int i = 7; i > 0; i--)
            gear[num - 1][i] = gear[num - 1][i - 1];
        gear[num - 1][0] = tmp;
    }
    else
    {
        int tmp = gear[num - 1][0];
        for (int i = 0; i < 7; i++)
            gear[num - 1][i] = gear[num - 1][i + 1];
        gear[num - 1][7] = tmp;
    }

    if (mode <= 0 && num >= 2 && touch[num - 1])
        rotation(num - 1, dir * -1, -1);
    if (mode >= 0 && num <= 3 && touch[num])
        rotation(num + 1, dir * -1, 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int rotate, num, dir;

    string str;
    for (int i = 0; i < 4; i++)
    {
        cin >> str;
        for (int j = 0; j < 8; j++)
        {
            gear[i][j] = str[j] - '0';
        }
    }
    cin >> rotate;
    for (int i = 0; i < rotate; i++)
    {
        cin >> num >> dir; // dir:1 시계, dir:-1 반시계

        for (int j = 1; j < 4; j++)
        {
            if (gear[j - 1][2] != gear[j][6])
            {
                touch[j] = true;
            }
        }
        rotation(num, dir, 0);
        memset(touch, 0, sizeof(touch));
    }

    int sumScore = 0;
    int score = 1;
    for (int i = 0; i < 4; i++)
    {
        if (gear[i][0] == 1)
            sumScore += score;
        score *= 2;
    }
    cout << sumScore << "\n";
    return 0;
}