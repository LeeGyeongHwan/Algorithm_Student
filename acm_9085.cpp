/* 
ACMICPC 
문제 번호 : 9085
문제 제목 : 더하기
풀이 날짜 : 2020-06-12
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num, tmp;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        int sumNum = 0;

        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            sumNum += tmp;
        }
        cout << sumNum << endl;
    }
    return 0;
}