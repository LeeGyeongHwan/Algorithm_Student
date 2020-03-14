/*
ACMICPC
문제 번호 : 10996
문제 제목 : 별 찍기 - 21
풀이 날짜 : 2020-03-14
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num * 2; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    cout << "*";
                else
                    cout << " ";
            }
            else
            {
                if (j % 2 == 0)
                    cout << " ";
                else
                    cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}