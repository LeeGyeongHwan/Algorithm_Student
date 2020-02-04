/*
난이도 : D1
문제 번호 : 2047
문제 제목 : 신문 헤드라인
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    string headline;

    cin >> headline;
    for (int i = 0; i < headline.length(); i++)
    {
        if (headline[i] >= 97 && headline[i] <= 122)
            cout << char(headline[i] - 32);
        else
            cout << headline[i];
    }

    return 0;
}