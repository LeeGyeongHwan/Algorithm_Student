/*
난이도 : D3
문제 번호 : 7102
문제 제목 : 준홍이의 카드놀이   
풀이 날짜 : 2020-02-05
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, M;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int start, end;
        cin >> N >> M;

        if (N > M)
        {
            start = M + 1;
            end = N + 1;
        }
        else
        {
            start = N + 1;
            end = M + 1;
        }

        cout << "#" << (i + 1);
        for (int j = start; j <= end; j++)
            cout << " " << j;
        cout << endl;
    }
    return 0;
}