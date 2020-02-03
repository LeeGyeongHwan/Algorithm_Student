/*
난이도 : D3
문제 번호 : 3456
문제 제목 : 직사각형 길이 찾기
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, line1, line2, line3;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> line1 >> line2 >> line3;

        cout << "#" << (i + 1) << " " << (line1 ^ line2 ^ line3) << endl;
    }
    return 0;
}