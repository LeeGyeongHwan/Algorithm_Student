/*
ACMICPC
문제 번호 : 4880
문제 제목 : 다음수
풀이 날짜 : 2020-03-20
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B, C;

    while (1)
    {
        bool isAP = false;
        cin >> A >> B >> C;
        if (A == 0 && B == 0 && C == 0)
            break;
        if (B - A == C - B)
            isAP = true;

        if (isAP)
            cout << "AP " << C + (C - B) << endl;
        else
            cout << "GP " << C * (C / B) << endl;
    }
    return 0;
}