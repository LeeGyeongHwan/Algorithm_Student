/*
난이도 : D3
문제 번호 : 9997
문제 제목 : 미니멀리즘 시계
풀이 날짜 : 2020-07-29
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, degree;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> degree;
        int hour = degree / 30;
        int min = degree % 30 * 2;

        cout << "#" << i + 1 << " " << hour << " " << min << endl;
    }

    return 0;
}