/*
난이도 : D3
문제 번호 : 1206
문제 제목 : View
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int testCase, tmp;
    int building[1001] = {0};
    for (int i = 0; i < 10; i++)
    {
        int numOfRight = 0;
        cin >> testCase;
        for (int j = 0; j < testCase; j++)
        {
            cin >> tmp;
            building[j] = tmp;
        }

        for (int j = 0; j < testCase; j++)
        {
            int maxHeight = 0;
            if (j - 2 >= 0 && building[j - 2] >= maxHeight)
                maxHeight = building[j - 2];
            if (j - 1 >= 0 && building[j - 1] >= maxHeight)
                maxHeight = building[j - 1];
            if (j + 1 <= testCase - 1 && building[j + 1] >= maxHeight)
                maxHeight = building[j + 1];
            if (j + 2 <= testCase - 1 && building[j + 2] >= maxHeight)
                maxHeight = building[j + 2];

            if (building[j] > maxHeight)
                numOfRight += (building[j] - maxHeight);
        }

        cout << "#" << (i + 1) << " " << numOfRight << endl;
        memset(building, 0, sizeof(building));
    }
    return 0;
}