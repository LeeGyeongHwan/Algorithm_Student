/*
ACMICPC
문제 번호 : 10025
문제 제목 : 게으른 백곰
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>

using namespace std;

int cage[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int ice, x;

    cin >> N >> K;
    int left = 1000000;
    int totalIce = 0;
    int right = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> ice >> x;
        cage[x] = ice;
        totalIce += ice;
        if (left > x)
            left = x;
        if (right < x)
            right = x;
    }

    if ((right - left) / 2 <= K)
    {
        cout << totalIce << "\n";
    }
    else
    {
        int partSum = 0;
        for (int i = left; i <= left + K + K; i++)
            partSum += cage[i];
        int maxSum = partSum;
        for (int i = left + K; i < right - K; i++)
        {
            partSum = partSum - cage[i - K] + cage[i + K + 1];
            if (partSum > maxSum)
                maxSum = partSum;
        }
        cout << maxSum << "\n";
    }

    return 0;
}
