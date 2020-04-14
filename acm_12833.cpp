/*
ACMICPC
문제 번호 : 12833
문제 제목 : XORXORXOR
풀이 날짜 : 2020-04-14
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int num = C % 2;

    for (int i = 0; i < num; i++)
    {
        A = A ^ B;
    }
    cout << A << endl;
    return 0;
}