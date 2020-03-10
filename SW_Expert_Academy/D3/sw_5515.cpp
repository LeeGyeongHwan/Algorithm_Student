/*
난이도 : D3
문제 번호 : 5515
문제 제목 : 2016년 요일 맞추기
풀이 날짜 : 2020-03-10
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testCase, m, d;
    int start = 4;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int totalDay = 0;
        cin >> m >> d;
        for (int j = 1; j < m; j++)
        {
            if (j == 2)
                totalDay += 29;
            else if (j == 4 || j == 6 || j == 9 || j == 11)
                totalDay += 30;
            else
                totalDay += 31;
        }
        totalDay += (d - 1);
        cout << "#" << (i + 1) << " " << (totalDay + start) % 7 << endl;
    }
    return 0;
}