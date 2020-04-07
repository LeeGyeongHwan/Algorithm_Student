/*
ACMICPC
문제 번호 : 17338
문제 제목 : 와글와글 숭고한
풀이 날짜 : 2020-04-07
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int S, K, H;
    cin >> S >> K >> H;

    if (S + K + H >= 100)
        cout << "OK" << endl;
    else
    {
        if (S > K)
        {
            if (K > H)
                cout << "Hanyang" << endl;
            else
                cout << "Korea" << endl;
        }
        else
        {
            if (S < H)
                cout << "Soongsil" << endl;
            else
                cout << "Hanyang" << endl;
        }
    }

    return 0;
}