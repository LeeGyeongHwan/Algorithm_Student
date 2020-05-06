/*
ACMICPC
문제 번호 : 2869
문제 제목 : 달팽이는 올라가고 싶다
풀이 날짜 : 2020-05-06
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B, V;
    cin >> A >> B >> V;
    int day = (V - B - 1) / (A - B);

    cout << day + 1 << endl;
    return 0;
}