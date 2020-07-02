/* 
ACMICPC 
문제 번호 : 10984
문제 제목 : 내 학점을 구해줘
풀이 날짜 : 2020-07-02
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int T, subject;
    int credit;
    double grade;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> subject;

        int totalCredit = 0;
        double GPA = 0;
        for (int j = 0; j < subject; j++)
        {
            cin >> credit >> grade;
            totalCredit += credit;
            GPA += credit * grade;
        }
        cout << totalCredit << " ";
        cout.precision(1);
        cout << fixed;
        cout << GPA / totalCredit << endl;
    }

    return 0;
}