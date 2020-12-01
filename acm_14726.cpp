/*
ACMICPC
문제 번호 : 14726
문제 제목 : 신용카드 판별
풀이 날짜 : 2020-12-01
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int T;
    string card;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> card;
        int sum = 0;
        for (int j = 0; j < card.length(); j++)
        {
            if (j % 2 == 0)
            {
                int tmp = card[j] - '0';
                tmp *= 2;
                sum += tmp / 10 + tmp % 10;
            }
            else
                sum += card[j] - '0';
        }
        if (sum % 10 == 0)
            cout << "T\n";
        else
            cout << "F\n";
    }

    return 0;
}