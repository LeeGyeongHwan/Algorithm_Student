/*
난이도 : D3
문제 번호 : 3408
문제 제목 : 세가지 합 구하기
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    long long num, S1, S2, S3;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        S2 = 0, S3 = 0;
        cin >> num;
        S1 = num * (num + 1) / 2;
        S3 = S1 * 2;
        S2 = S3 - num;
        cout << "#" << (i + 1) << " " << S1 << " " << S2 << " " << S3 << "\n";
    }
    return 0;
}