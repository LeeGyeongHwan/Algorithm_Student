/* 
ACMICPC 
문제 번호 : 15814
문제 제목 : 야바위 대장
풀이 날짜 : 2020-06-13
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int T;
    int A, B;
    char tmp;

    cin >> str;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        tmp = str[A];
        str[A] = str[B];
        str[B] = tmp;
    }
    cout << str << endl;

    return 0;
}