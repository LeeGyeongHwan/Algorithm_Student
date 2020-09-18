/*
ACMICPC
문제 번호 : 2921
문제 제목 : 도미노
풀이 날짜 : 2020-09-18
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;

    for (int i = 0; i <= N; i++)
        for (int j = i; j <= N; j++)
            sum += (i + j);
    cout << sum << "\n";
}