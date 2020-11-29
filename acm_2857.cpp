/*
ACMICPC
문제 번호 : 2857
문제 제목 : FBI
풀이 날짜 : 2020-11-29
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;

    for (int i = 1; i <= 5; i++)
    {
        cin >> str;
        if (str.find("FBI") != string::npos)
            cout << i << " ";
    }
}