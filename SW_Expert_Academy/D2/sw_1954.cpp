/*
난이도 : D2
문제 번호 : 1954
문제 제목 : 달팽이 숫자
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, num;
    int snail[10][10] = {0};
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int startNum = 0, x = 0, y = -1;
        bool isForward = false;
        cin >> num;

        for (int j = num * 2; j > 0; j--)
        {
            if (j % 2 == 0)
                isForward = isForward ? 0 : 1;

            for (int k = 0; k < j / 2; k++)
            {
                startNum++;
                if (j % 2 == 0)
                {
                    if (isForward)
                        y++;
                    else
                        y--;
                }
                else
                {
                    if (isForward)
                        x++;
                    else
                        x--;
                }
                snail[x][y] = startNum;
            }
        }

        cout << "#" << (i + 1) << endl;
        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
                cout << snail[j][k] << " ";
            cout << endl;
        }
        memset(snail, 0, sizeof(snail));
    }
    return 0;
}
