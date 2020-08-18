/*
ACMICPC
문제 번호 : 1920
문제 제목 : 수 찾기
풀이 날짜 : 2020-08-18
Solved By Reamer
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, tmp;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
    }
    sort(arr, arr + N);

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> tmp;
        int leftI = 0;
        int rightI = N - 1;
        bool isAnswer = false;
        while (leftI <= rightI)
        {
            int tmpIdx = (leftI + rightI) / 2;
            if (arr[tmpIdx] == tmp)
            {
                isAnswer = true;
                break;
            }
            if (tmp < arr[tmpIdx])
                rightI = tmpIdx - 1;
            else
                leftI = tmpIdx + 1;
        }
        if (isAnswer)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}