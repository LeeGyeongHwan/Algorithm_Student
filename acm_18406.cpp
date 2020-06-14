/* 
ACMICPC 
문제 번호 : 18406
문제 제목 : 럭키 스트레이트
풀이 날짜 : 2020-06-14
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int sumA = 0, sumB = 0;
    cin >> str;

    for (int i = 0; i < str.length() / 2; i++)
    {
        sumA += (int)(str[i] - '0');
    }
    for (int i = str.length() / 2; i < str.length(); i++)
    {
        sumB += (int)(str[i] - '0');
    }
    if (sumA == sumB)
        cout << "LUCKY" << endl;
    else
        cout << "READY" << endl;

    return 0;
}