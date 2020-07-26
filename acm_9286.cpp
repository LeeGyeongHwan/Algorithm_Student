/* 
ACMICPC 
문제 번호 : 9286
문제 제목 : Gradabase 
풀이 날짜 : 2020-07-27
Solved By Reamer 
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase, student, tmp;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> student;
        cout << "Case " << i + 1 << ":\n";
        for (int j = 0; j < student; j++)
        {
            cin >> tmp;
            if (tmp + 1 <= 6)
                cout << tmp + 1 << "\n";
        }
    }

    return 0;
}