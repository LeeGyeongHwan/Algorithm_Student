/*
ACMICPC
문제 번호 : 11729
문제 제목 : 하노이 탑 이동 순서
풀이 날짜 : 2020-10-27
Solved By Reamer
*/

#include <iostream>

using namespace std;

void printRoute(int x, int y)
{
    cout << x << " " << y << "\n";
}

void hanoi(int N, int start, int by, int end)
{
    if (N == 1)
    {
        printRoute(start, end);
        return;
    }

    hanoi(N - 1, start, end, by);
    printRoute(start, end);
    hanoi(N - 1, by, start, end);
}

int main()
{
    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 2, 3);
    return 0;
}