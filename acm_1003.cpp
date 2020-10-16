/*
ACMICPC
문제 번호 : 1003
문제 제목 : 피보나치 함수
풀이 날짜 : 2020-10-16
Solved By Reamer
*/

#include <iostream>

using namespace std;
int arr[41][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;

    cin >> T;

    arr[0][0] = 1;
    arr[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << arr[N][0] << " " << arr[N][1] << "\n";
    }

    return 0;
}