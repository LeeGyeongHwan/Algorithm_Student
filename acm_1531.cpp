/*
ACMICPC
문제 번호 : 1531
문제 제목 : 투명
풀이 날짜 : 2020-07-11
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int paint[101][101] = {0};
    int N, M;
    int x1, y1, x2, y2;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                paint[j][k]++;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (paint[i][j] > M)
                answer++;
        }
    }

    cout << answer << endl;
    return 0;
}