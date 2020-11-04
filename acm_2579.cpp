/* 
ACMICPC 
문제 번호 : 2579
문제 제목 : 계단 오르기
풀이 날짜 : 2020-11-04
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int stairs[301];
int N;
int maxSum = 0;
int dp[301][2];
void findRoute(int cnt, int continuous, int sum)
{

    if (cnt > 0)
    {
        if (dp[cnt][continuous - 1] > sum)
            return;
        dp[cnt][continuous - 1] = sum;
    }

    if (cnt == N)
    {
        if (maxSum < sum)
            maxSum = sum;
        return;
    }

    if (continuous == 2)
    {
        if (cnt + 2 <= N)
            findRoute(cnt + 2, 1, sum + stairs[cnt + 2]);
    }
    else
    {
        if (cnt + 1 <= N)
            findRoute(cnt + 1, continuous + 1, sum + stairs[cnt + 1]);
        if (cnt + 2 <= N)
            findRoute(cnt + 2, 1, sum + stairs[cnt + 2]);
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];

    findRoute(0, 0, 0);
    cout << maxSum << endl;
    return 0;
}