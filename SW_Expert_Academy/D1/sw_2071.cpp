/*
난이도 : D1
문제 번호 : 2071
문제 제목 : 평균값 구하기
풀이 날짜 : 2020-02-01
Solved By Reamer
*/

#include <iostream>
#include <cmath>

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
                testSum += tmp;
        }
        float avg = (float)testSum/10;
        cout << "#" << (i + 1) << " " << round(avg) << endl;
    }
    return 0;
}