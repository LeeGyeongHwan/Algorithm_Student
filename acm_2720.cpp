/* 
ACMICPC 
문제 번호 : 2720
문제 제목 : 세탁소 사장 동혁
풀이 날짜 : 2020-07-04
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, money;
    int quarter, dime, nickel, penny;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> money;

        quarter = money / 25;
        money %= 25;
        dime = money / 10;
        money %= 10;
        nickel = money / 5;
        money %= 5;
        penny = money;

        cout << quarter << " " << dime << " " << nickel << " " << penny << endl;
    }

    return 0;
}