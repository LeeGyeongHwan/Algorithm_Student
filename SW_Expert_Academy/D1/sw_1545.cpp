/*
난이도 : D1
문제 번호 : 1545
문제 제목 : 거꾸로 출력해 보아요
풀이 날짜 : 2020-02-15
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = num; i >= 0; i--)
        cout << i << " ";
    return 0;
}