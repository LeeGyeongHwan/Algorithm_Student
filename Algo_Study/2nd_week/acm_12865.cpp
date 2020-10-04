/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 12865
문제 제목 : 평범한 배낭
풀이 날짜 : 2020-10-05
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int weights[101];
int profits[101];
int dp[100001];

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> weights[i] >> profits[i];

    for (int i = 1; i <= N; i++)
    {
        for (int w = K; w >= weights[i]; w--)
        {
            if (dp[w] < profits[i] + dp[w - weights[i]])
                dp[w] = profits[i] + dp[w - weights[i]];
        }
    }
    cout << dp[K] << "\n";
    return 0;
}