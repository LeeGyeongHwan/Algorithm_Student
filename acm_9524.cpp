/*
ACMICPC
문제 번호 : 9424
문제 제목 : Beautiful Yekaterinburg
풀이 날짜 : 2020-07-22
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    char found[] = {'1', '7', '2', '3'};
    int num;

    cin >> num;

    cout << (int)(found[num - 1] - '0') << endl;

    return 0;
}