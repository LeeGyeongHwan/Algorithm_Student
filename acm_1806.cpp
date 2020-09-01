/*
ACMICPC
문제 번호 : 1806
문제 제목 : 부분합
풀이 날짜 : 2020-09-01
Solved By Reamer
*/

#include <iostream>

using namespace std;

int arr[100001];
int main()
{
    int N, S, tmp;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int minLen = 100001;
    int start = 0, end = 0, tmpSum = 0;
    while (true)
    {
        if (tmpSum >= S)
        {
            if (minLen > end - start)
                minLen = end - start;
            tmpSum -= arr[start++];
        }
        else if (end == N)
            break;
        else
        {
            tmpSum += arr[end++];
        }
    }
    if (minLen == 100001)
        cout << "0\n";
    else
        cout << minLen << "\n";

    return 0;
}