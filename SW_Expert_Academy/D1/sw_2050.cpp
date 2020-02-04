/*
난이도 : D1
문제 번호 : 2050
문제 제목 : 알파벳을 숫자로 변환
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    string alphabet;

    cin >> alphabet;
    for (int i = 0; i < alphabet.length(); i++)
    {
        cout << alphabet[i] - 'A' + 1 << " ";
    }

    return 0;
}