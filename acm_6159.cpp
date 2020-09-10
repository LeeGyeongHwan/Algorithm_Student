/*
ACMICPC
문제 번호 : 6159
문제 제목 : 코스튬 파티
풀이 날짜 : 2020-09-10
Solved By Reamer
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> intVec;
    int N, K, cow;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> cow;
        intVec.push_back(cow);
    }
    sort(intVec.begin(), intVec.end());

    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (intVec[i] > K)
            break;
        for (int j = i + 1; j < N; j++)
        {
            if (intVec[i] + intVec[j] <= K)
                sum++;
            else
                break;
        }
    }
    cout << sum << "\n";

    return 0;
}