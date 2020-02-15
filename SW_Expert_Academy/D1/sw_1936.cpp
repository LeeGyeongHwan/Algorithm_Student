/*
난이도 : D1
문제 번호 : 1936
문제 제목 : 1대1 가위바위보
풀이 날짜 : 2020-02-15
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if ((A == 1 && B == 2) || (A == 2 && B == 3) || (A == 3 && B == 1))
        cout << "B" << endl;
    else
        cout << "A" << endl;

    return 0;
}