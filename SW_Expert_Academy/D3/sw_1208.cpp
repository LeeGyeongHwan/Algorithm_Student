/*
난이도 : D3
문제 번호 : 1208
문제 제목 : Flatten
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dump, tmp;
    int box[101] = {0};
    int heightCount[101] = {0};
    for (int i = 0; i < 10; i++)
    {
        cin >> dump;
        int dumpCpy = dump;
        int maxHeight = 0;
        int minHeight = 100;
        for (int j = 0; j < 100; j++)
        {
            cin >> tmp;
            box[j] = tmp;
            heightCount[tmp]++;
            if (tmp > maxHeight)
                maxHeight = tmp;
            if (tmp < minHeight)
                minHeight = tmp;
        }

        while (dump >= 0)
        {
            int numBox = heightCount[maxHeight];
            dump -= numBox;
            maxHeight--;
            heightCount[maxHeight] += numBox;
        }

        while (dumpCpy >= 0)
        {
            int numBox = heightCount[minHeight];
            dumpCpy -= numBox;
            minHeight++;
            heightCount[minHeight] += numBox;
        }
        maxHeight++;
        minHeight--;

        cout << "#" << (i + 1) << " " << maxHeight - minHeight << endl;
        memset(box, 0, sizeof(box));
        memset(heightCount, 0, sizeof(heightCount));
    }
    return 0;
}