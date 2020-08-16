/* 
ACMICPC 
문제 번호 : 10164
문제 제목 : 격자상의 경로
풀이 날짜 : 2020-08-16
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int H(int n, int r)
{
    n = n + r - 1;
    long long num = 1;

    for (int i = 0; i < r; i++)
        num *= (n - i);
    for (int i = 1; i <= r; i++)
        num /= i;
    return (int)num;
}

int main()
{
    int board[16][16] = {0};
    int N, M, K;
    cin >> N >> M >> K;
    int maxNum, minNum;
    if (K == 0)
    {
        cout << H(max(N, M), min(N, M) - 1) << endl;
    }
    else
    {

        int y = K % M == 0 ? M : K % M;
        int x = y == M ? K / M : K / M + 1;
        cout << H(max(x, y), min(x, y) - 1) * H(max(N - x, M - y) + 1, min(N - x, M - y)) << endl;
    }
    return 0;
}