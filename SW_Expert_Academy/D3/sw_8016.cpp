/*
난이도 : D3
문제 번호 : 8016
문제 제목 : 홀수 피라미드
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    long long floor, left, right;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> floor;
        left = (floor - 1) * (floor - 1) * 2 + 1;
        right = floor * floor * 2 - 1;

        cout << "#" << (i + 1) << " " << left << " " << right << endl;
    }
    return 0;
}