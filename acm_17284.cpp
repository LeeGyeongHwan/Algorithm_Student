/*
ACMICPC
문제 번호 : 17284
문제 제목 : Vending Machine
풀이 날짜 : 2020-03-18
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int num;
    int total = 5000;
    int price[] = {500, 800, 1000};

    while (1)
    {
        cin >> num;
        if (cin.eof() == true)
            break;
        total -= price[num - 1];
    }

    cout << total << endl;

    return 0;
}