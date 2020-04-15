/*
ACMICPC
문제 번호 : 15964
문제 제목 : 이상한 기호
풀이 날짜 : 2020-04-15
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;

    cout << (A + B) * (A - B) << endl;

    return 0;
}