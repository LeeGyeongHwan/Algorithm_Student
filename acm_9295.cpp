/* 
ACMICPC 
문제 번호 : 9295
문제 제목 : 주사위 
풀이 날짜 : 2020-07-05
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> A >> B;

        cout << "Case " << i + 1 << ": " << A + B << endl;
    }
    return 0;
}