/*
ACMICPC
문제 번호 : 16483
문제 제목 : 접시 안의 원
풀이 날짜 : 2020-03-17
Solved By Reamer
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T;
    float halfT;
    cin >> T;
    halfT = (float)T / 2;

    T = round(halfT * halfT);

    cout << T << endl;
    return 0;
}