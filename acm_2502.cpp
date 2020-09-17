/*
ACMICPC
문제 번호 : 2502
문제 제목 : 떡 먹는 호랑이
풀이 날짜 : 2020-09-17
Solved By Reamer
*/

#include <iostream>

using namespace std;

int riceCake[30];
int fibo[30];

int fibonacci(int idx, int dest)
{
    riceCake[idx] = riceCake[idx - 1] + riceCake[idx - 2];
    if (idx == dest - 1)
        return riceCake[idx];
    else
        return fibonacci(idx + 1, dest);
}

int main()
{
    int D, K;
    cin >> D >> K;

    for (int i = 1; i < K; i++)
    {
        for (int j = i; j < K; j++)
        {
            riceCake[0] = i;
            riceCake[1] = j;
            if (fibonacci(2, D) == K)
            {
                cout << i << "\n"
                     << j;
                return 0;
            }
        }
    }
}