/*
ACMICPC
문제 번호 : 16486
문제 제목 : 운동장 한 바퀴
풀이 날짜 : 2020-04-28
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    const double pie = 3.141592;
    int d1, d2;
    cin >> d1 >> d2;
    double answer = 2 * ((double)d1 + d2 * pie);

    cout << fixed;
    cout.precision(6);
    cout << answer << endl;

    return 0;
}