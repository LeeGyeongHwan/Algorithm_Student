/*
ACMICPC
문제 번호 : 2789
문제 제목 : 유학 금지
풀이 날짜 : 2020-07-10
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E'))
            cout << str[i];
    }
    return 0;
}