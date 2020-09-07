/*
ACMICPC
문제 번호 : 2559
문제 제목 : 수열
풀이 날짜 : 2020-09-07
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, tmp;
    vector<int> intVec;
    cin >> N >> K;

    int tmpSum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
        if (i < K)
            tmpSum += tmp;
    }
    int maxSum = tmpSum;
    
    for (int i = 0; i < N - K; i++)
    {
        tmpSum = tmpSum - intVec[i] + intVec[i + K];
        if (tmpSum > maxSum)
            maxSum = tmpSum;
    }
    cout << maxSum << "\n";
    return 0;
}
