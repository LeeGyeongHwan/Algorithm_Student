/*
ACMICPC
문제 번호 : 5724
문제 제목 : 파인만
풀이 날짜 : 2020-10-26
Solved By Reamer
*/

#include <iostream>

using namespace std;

int arr[101];

int main()
{
    int num;

    for (int i = 1; i <= 100; i++)
        arr[i] = arr[i - 1] + i * i;

    while (true)
    {
        cin >> num;
        if (num == 0)
            break;
        cout << arr[num] << "\n";
    }

    return 0;
}