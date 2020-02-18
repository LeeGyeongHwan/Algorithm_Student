/*
난이도 : D3
문제 번호 : 3233
문제 제목 : 정삼각형 분할 놀이
풀이 날짜 : 2020-02-18
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> A >> B;
        long long num = A / B;
        cout << "#" << (i + 1) << " " << num * num << endl;
    }

    return 0;
}