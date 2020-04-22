/*
ACMICPC
문제 번호 : 10768
문제 제목 : 특별한 날
풀이 날짜 : 2020-04-22
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int month, day;

    cin >> month >> day;

    if (month < 2)
        cout << "Before" << endl;
    else if (month > 2)
        cout << "After" << endl;
    else
    {
        if (day < 18)
            cout << "Before" << endl;
        else if (day > 18)
            cout << "After" << endl;
        else
            cout << "Special" << endl;
    }

    return 0;
}