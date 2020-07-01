/* 
ACMICPC 
문제 번호 : 9546
문제 제목 : 3000번 버스
풀이 날짜 : 2020-07-01
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, tmp;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> tmp;
        double people = 0;
        for (int j = 0; j < tmp; j++)
        {
            people = (people + 0.5) * 2;
        }
        cout << (int)people << endl;
    }
    return 0;
}