/*
ACMICPC
문제 번호 : 2965
문제 제목 : 캥거루 세마리
풀이 날짜 : 2020-09-26
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int maxNum = B - A > C - B ? B - A : C - B;
    cout << maxNum -1 << "\n";
    return 0;
}