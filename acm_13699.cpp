/*
ACMICPC
문제 번호 : 13699
문제 제목 : 점화식
풀이 날짜 : 2020-10-30
Solved By Reamer
*/

#include <iostream>

using namespace std;

long long arr[36];

int main()
{
    int N;

    cin >> N;

    arr[0] = 1;

    for (int i = 1; i <= 35; i++)
    {
        for (int j = 0; j < i; j++)
            arr[i] += arr[j] * arr[i - j - 1];
    }

    cout << arr[N] << "\n";

    return 0;
}