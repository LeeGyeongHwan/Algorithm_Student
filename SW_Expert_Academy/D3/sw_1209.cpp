/*
난이도 : D3
문제 번호 : 1209
문제 제목 : Sum 
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
    int rowSum[100] = {0};
    int colSum[100] = {0};

    for (int i = 0; i < 10; i++)
    {
        cin >> testCase;
        int crossSum = 0;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                cin >> tmp;
                rowSum[j] += tmp;
                colSum[k] += tmp;
                if (j == k)
                    crossSum += tmp;
            }
        }
        int maxNum = 0;
        for (int j = 0; j < 100; j++)
        {
            if (rowSum[j] > maxNum)
                maxNum = rowSum[j];
            if (colSum[j] > maxNum)
                maxNum = colSum[j];
        }
        if (crossSum > maxNum)
            maxNum = crossSum;

        cout << "#" << testCase << " " << maxNum << endl;
        memset(rowSum, 0, sizeof(rowSum));
        memset(colSum, 0, sizeof(colSum));
    }
    return 0;
}