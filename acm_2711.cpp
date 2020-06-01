/* 
ACMICPC 
문제 번호 : 2711
문제 제목 : 오타맨 고창영
풀이 날짜 : 2020-06-01
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testCase;
    int index;
    string str;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> index >> str;

        for (int j = 0; j < str.length(); j++)
        {
            if (index - 1 == j)
                continue;
            else
                cout << str[j];
        }
        cout << "\n";
    }
    return 0;
}