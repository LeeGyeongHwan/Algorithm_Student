/*
ACMICPC
문제 번호 : 1940
문제 제목 : 주몽
풀이 날짜 : 2020-09-05
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
    vector<int> intVec;
    int N, M, tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());

    int start = 0, end = intVec.size() - 1;
    int cnt = 0;
    while (true)
    {
        if (intVec[start] + intVec[end] > M)
            end--;
        else if (intVec[start] + intVec[end] < M)
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