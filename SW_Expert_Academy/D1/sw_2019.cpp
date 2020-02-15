/*
난이도 : D1
문제 번호 : 2019
문제 제목 : 더블더블
풀이 날짜 : 2020-02-15
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int num, mul = 1;
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
        cout << mul << " ";
        mul *= 2;
    }
    return 0;
}