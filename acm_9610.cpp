/* 
ACMICPC 
문제 번호 : 9610
문제 제목 : 사분면
풀이 날짜 : 2020-07-06
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int point, x, y;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;

    cin >> point;

    for (int i = 0; i < point; i++)
    {
        cin >> x >> y;
        if (x > 0 && y > 0)
            q1++;
        else if (x < 0 && y > 0)
            q2++;
        else if (x < 0 && y < 0)
            q3++;
        else if (x > 0 && y < 0)
            q4++;
        else
            axis++;
    }

    cout << "Q1: " << q1 << endl;
    cout << "Q2: " << q2 << endl;
    cout << "Q3: " << q3 << endl;
    cout << "Q4: " << q4 << endl;
    cout << "AXIS: " << axis << endl;

    return 0;
}
