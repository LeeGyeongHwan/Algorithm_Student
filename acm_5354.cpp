/* 
ACMICPC 
문제 번호 : 5354
문제 제목 : J박스
풀이 날짜 : 2020-06-24
Solved By Reamer 
*/

#include <iostream>
using namespace std;

int main()
{
    int testCase, num;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                if (j == 0 || j == num - 1 || k == 0 || k == num - 1)
                    cout << "#";
                else
                    cout << "J";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}