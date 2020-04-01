/*
ACMICPC
문제 번호 : 15813
문제 제목 : 너의 이름은 몇 점이니?
풀이 날짜 : 2020-04-01
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int leng, total = 0;
    char alpha;
    cin >> leng;
    for (int i = 0; i < leng; i++)
    {
        cin >> alpha;
        total += (int)(alpha - 'A') + 1;
    }
    cout << total << endl;
    return 0;
}