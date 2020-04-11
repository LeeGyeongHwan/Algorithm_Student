/* 
ACMICPC 
문제 번호 : 1550 
문제 제목 : 16진수
풀이 날짜 : 2020-04-11
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int num = 0;
    int mul = 1;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        char tmp = str[str.length() - i - 1];
        if (tmp < 58)
            num += (int)(tmp - '0') * mul;
        else
            num += ((int)(tmp - 'A') + 10) * mul;

        mul *= 16;
    }
    cout<<num<<endl;
    return 0;
}