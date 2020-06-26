/* 
ACMICPC 
문제 번호 : 10179
문제 제목 : 쿠폰
풀이 날짜 : 2020-06-27
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    double price;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> price;

        cout.precision(2);
        cout << fixed;
        cout << "$" << price * 0.8 << endl;
    }
    return 0;
}