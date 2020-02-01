/*
난이도 : D4
문제 번호 : 1210
문제 제목 : Ladder1 
풀이 날짜 : 2020-02-01
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;
    int ladder[100][100] = {0};

    for (int i = 0; i < 10; i++)
    {
        cin >> testCase;
        pair<int, int> xy;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                cin >> tmp;
                ladder[j][k] = tmp;
                if (tmp == 2)
                    xy = make_pair(j, k);
            }
        }

        int isRight = 0;
        int isLeft = 0;
        while (xy.first > 0)
        {
            int x = xy.first;
            int y = xy.second;

            if (y - 1 >= 0 && ladder[x][y - 1] == 1 && !isRight)
            {
                xy.second = y - 1;
                isRight = 0;
                isLeft = 1;
            }
            else if (y + 1 <= 99 && ladder[x][y + 1] == 1 && !isLeft)
            {
                xy.second = y + 1;
                isRight = 1;
                isLeft = 0;
            }
            else
            {
                xy.first = x - 1;
                isRight = 0;
                isLeft = 0;
            }
        }

        cout << "#" << testCase << " " << xy.second << endl;
        memset(ladder, 0, sizeof(ladder));
    }
    return 0;
}