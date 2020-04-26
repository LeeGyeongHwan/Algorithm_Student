/*
ACMICPC
문제 번호 : 18883
문제 제목 : N M 찍기
풀이 날짜 : 2020-04-26
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << j + 1 + i * M;
            if (j != M - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}