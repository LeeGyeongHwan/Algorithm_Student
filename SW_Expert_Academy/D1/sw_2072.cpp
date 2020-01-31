/*
난이도 : D1
문제 번호 : 2072
문제 제목 : 홀수만 더하기
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, tmp;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int testSum = 0;
        for (int j = 0; j < 10; j++)
        {
            cin >> tmp;
            if (tmp % 2 == 1)
                testSum += tmp;
        }
        cout << "#" << (i + 1) << " " << testSum << endl;
    }
    return 0;
}