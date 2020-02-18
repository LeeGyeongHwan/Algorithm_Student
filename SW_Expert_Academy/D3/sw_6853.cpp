/*
난이도 : D3
문제 번호 : 6853
문제 제목 : 직사각형과 점
풀이 날짜 : 2020-02-18
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, x1, y1, x2, y2;
    int x, y, number;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int case1 = 0, case2 = 0, case3 = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        cin >> number;
        for (int j = 0; j < number; j++)
        {
            cin >> x >> y;
            if (x > x1 && x < x2 && y > y1 && y < y2)
                case1++;
            else if ((x == x1 && y >= y1 && y <= y2) || (x == x2 && y >= y1 && y <= y2) || (y == y1 && x >= x1 && x <= x2) || (y == y2 && x >= x1 && x <= x2))
                case2++;
            else
                case3++;
        }

        cout << "#" << (i + 1) << " " << case1 << " " << case2 << " " << case3 << "\n";
    }

    return 0;
}