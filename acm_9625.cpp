/*
ACMICPC
문제 번호 : 9625
문제 제목 : BABBA
풀이 날짜 : 2020-11-15
Solved By Reamer
*/

#include <iostream>

using namespace std;
int A[46], B[46];
int main()
{
    int K;
    cin >> K;
    A[0] = 1;
    for (int i = 1; i <= K; i++)
    {
        B[i] = B[i - 1] + A[i - 1];
        A[i] = B[i - 1];
    }
    cout << A[K] << " " << B[K] << "\n";
    return 0;
}