/*
ACMICPC
문제 번호 : 11055
문제 제목 : 가장 큰 증가 부분 수열
풀이 날짜 : 2020-08-04
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int arr[1000] = {0};
int dist[1000];

int main()
{
    int N, tmp;

    cin >> N;


    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 0)
            dist[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dist[i] < dist[j] + arr[i])
                {
                    dist[i] = dist[j] + arr[i];
                }
            }
        }
    }
    int maxLength = 0;
    for (int i = 0; i < N; i++)
    {
        if (dist[i] > maxLength)
            maxLength = dist[i];
    }
    cout << maxLength << endl;
    return 0;
}