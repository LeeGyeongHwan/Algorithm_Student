/*
ACMICPC
문제 번호 : 10991
문제 제목 : 별 찍기 - 16
풀이 날짜 : 2020-04-10
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
            cout << " ";
        for (int j = 0; j <= i + i; j++)
        {
            if (j % 2 == 0)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}