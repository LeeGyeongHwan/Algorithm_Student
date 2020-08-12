/*
ACMICPC
문제 번호 : 9372
문제 제목 : 상근이의 여행
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    int N, M;
    int x, y;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> N >> M;
        for (int j = 0; j < M; j++)
        {
            cin >> x >> y;
        }
        cout << N - 1 << endl;
    }
    return 0;
}