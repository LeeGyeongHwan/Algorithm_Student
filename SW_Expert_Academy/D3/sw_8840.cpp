/*
난이도 : D3
문제 번호 : 8840
문제 제목 : 아바바바
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
    long long sumPal, num;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        sumPal = (num / 2) * (num / 2);
        cout << "#" << (i + 1) << " " << sumPal << "\n";
    }
    return 0;
}