/*
ACMICPC
문제 번호 : 10815
문제 제목 : 숫자 카드
풀이 날짜 : 2020-08-18
Solved By Reamer
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        int leftI = 0;
        int rightI = N - 1;
        bool isAnswer = false;
        while (leftI <= rightI)
        {
            int midI = (leftI + rightI) / 2;
            if (arr[midI] == tmp)
            {
                isAnswer = true;
                break;
            }
            else if (arr[midI] > tmp)
                rightI = midI - 1;
            else
                leftI = midI + 1;
        }
        if (isAnswer)
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}