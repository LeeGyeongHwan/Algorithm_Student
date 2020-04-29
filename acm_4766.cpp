/*
ACMICPC
문제 번호 : 4766
문제 제목 : 일반 화학 실험
풀이 날짜 : 2020-04-29
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    double oldTemp, newTemp;

    cin >> newTemp;
    while (1)
    {
        oldTemp = newTemp;
        cin >> newTemp;
        if (newTemp == 999)
            break;

        cout << fixed;
        cout.precision(2);
        cout << newTemp - oldTemp << endl;
    }
    return 0;
}