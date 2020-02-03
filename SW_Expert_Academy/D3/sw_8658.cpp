/*
난이도 : D3
문제 번호 : 8658
문제 제목 : Summation  
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxNum = 0;
        int minNum = 54;
        for (int j = 0; j < 10; j++)
        {
            int sum = 0;
            cin >> tmp;
            do
            {
                sum += tmp % 10;
                tmp /= 10;
            } while (tmp != 0);
            if (sum > maxNum)
                maxNum = sum;
            if (sum < minNum)
                minNum = sum;
        }

        cout << "#" << (i + 1) << " " << maxNum << " " << minNum << endl;
    }
    return 0;
}