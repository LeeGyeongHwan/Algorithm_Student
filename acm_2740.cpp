/*
ACMICPC
문제 번호 : 2740
문제 제목 : 행렬 곱셈
풀이 날짜 : 2020-10-24
Solved By Reamer
*/

#include <iostream>

using namespace std;

int arr1[100][100], arr2[100][100];
int main()
{
    int N, M, K;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr1[i][j];

    cin >> M >> K;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> arr2[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int sum = 0;
            for (int k = 0; k < M; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}