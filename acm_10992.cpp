/*
ACMICPC
문제 번호 : 10992
문제 제목 : 별 찍기 - 17
풀이 날짜 : 2020-04-17
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
        if (i == num - 1)
        {
            for (int j = 0; j < num + num - 1; j++)
                cout << "*";
        }
        else
        {
            for (int j = 0; j <= i + i; j++)
            {
                if (j == 0 || j == i + i)
                    cout << "*";
                else
                    cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}