/*
난이도 : D2
문제 번호 : 1986
문제 제목 : 지그재그 숫자
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num, answer;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        if (num % 2 == 0)
            answer = 0 - num / 2;
        else
            answer = num - num / 2;
        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}