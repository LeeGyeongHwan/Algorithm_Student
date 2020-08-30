/*
ACMICPC
문제 번호 : 2003
문제 제목 : 수들의 합 2
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>
using namespace std;

int arr[10000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int answer = 0;
    int start = 0, end = 0;
    int tmpSum = 0;

    while (true)
    {
        if (tmpSum >= M)
            tmpSum -= arr[start++];
        else if (end == N)
            break;
        else
            tmpSum += arr[end++];

        if (tmpSum == M)
            answer++;
    }

    cout << answer << "\n";

    return 0;
}