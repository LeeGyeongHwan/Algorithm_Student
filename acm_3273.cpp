/*
ACMICPC
문제 번호 : 3273
문제 제목 : 두 수의 합
풀이 날짜 : 2020-09-06
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
    int N, tmp, X;
    vector<int> intVec;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    cin >> X;
    sort(intVec.begin(), intVec.end());

    int start = 0, end = N - 1;
    int cnt = 0;

    while (true)
    {
        if (intVec[start] + intVec[end] > X)
            end--;
        else if (intVec[start] + intVec[end] < X)
            start++;
        else
        {
            start++;
            end--;
            cnt++;
        }

        if (start >= end)
            break;
    }
    cout << cnt << "\n";
    return 0;
}