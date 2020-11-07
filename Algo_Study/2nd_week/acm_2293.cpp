/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 2293
문제 제목 : 동전 1
풀이 날짜 : 2020-11-07
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int dp[10001];
int main()
{
    int n, k, coin;

    cin >> n >> k;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> coin;
        for (int j = 1; j <= k; j++)
        {
            if (j >= coin)
            {
                dp[j] += dp[j - coin];
            }
        }
    }
    cout << dp[k] << endl;
}