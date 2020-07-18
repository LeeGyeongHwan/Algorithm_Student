/*
ACMICPC
문제 번호 : 16727
문제 제목 : ICPC
풀이 날짜 : 2020-07-18
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int p1, p2, s1, s2;

    cin >> p1 >> s1;
    cin >> s2 >> p2;

    if (p1 + p2 > s1 + s2)
        cout << "Persepolis" << endl;
    else if (p1 + p2 == s1 + s2)
    {
        if (s1 > p2)
            cout << "Esteghlal" << endl;
        else if (s1 == p2)
            cout << "Penalty" << endl;
        else
            cout << "Persepolis" << endl;
    }
    else
        cout << "Esteghlal" << endl;

    return 0;
}