/*
ACMICPC
문제 번호 : 10570
문제 제목 : Favorite Number
풀이 날짜 : 2020-07-24
Solved By Reamer
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int testCase, N, num;
    int numArr[1001] = {0};
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            cin >> num;
            numArr[num]++;
        }
        int index = 0;
        int maxNum = 0;
        for (int j = 1; j <= 1000; j++)
        {
            if (numArr[j] > maxNum)
            {
                index = j;
                maxNum = numArr[j];
            }
        }

        cout << index << endl;
        memset(numArr, 0, sizeof(numArr));
    }

    return 0;
}