/* 
ACMICPC 
문제 번호 : 18398
문제 제목 : HOMWRK
풀이 날짜 : 2020-07-28
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, problem;
    int A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> problem;
        for (int j = 0; j < problem; j++)
        {
            cin >> A >> B;
            cout << A + B << " " << A * B << endl;
        }
    }

    return 0;
}