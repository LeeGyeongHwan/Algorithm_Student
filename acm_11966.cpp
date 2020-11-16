/*
ACMICPC
문제 번호 : 11966
문제 제목 : 2의 제곱인가?
풀이 날짜 : 2020-11-17
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    while (N != 0)
    {
        if (N & 1 == 1)
            cnt++;
        if (cnt > 1)
            break;
        N >>= 1;
    }
    if (cnt == 1)
        cout << "1";
    else
        cout << "0";
    return 0;
}