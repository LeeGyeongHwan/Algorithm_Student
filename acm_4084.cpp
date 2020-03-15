/*
ACMICPC
문제 번호 : 4084
문제 제목 : Viva la Diferencia
풀이 날짜 : 2020-03-15
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B, C, D;
    int tmpA, tmpB, tmpC, tmpD;

    while (1)
    {
        int count = 0;
        cin >> A >> B >> C >> D;

        if (A == 0 && B == 0 && C == 0 && D == 0)
            break;

        while (!(A == B && B == C && C == D))
        {
            tmpA = abs(A - B);
            tmpB = abs(B - C);
            tmpC = abs(C - D);
            tmpD = abs(D - A);
            A = tmpA;
            B = tmpB;
            C = tmpC;
            D = tmpD;
            count++;
        }
        cout << count << endl;
    }

    return 0;
}