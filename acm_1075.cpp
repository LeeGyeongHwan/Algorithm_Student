/*
ACMICPC
문제 번호 : 1075
문제 제목 : 나누기
풀이 날짜 : 2020-07-13
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int N, F;

    cin >> N >> F;

    int num = N / 100 * 100;
    for (int i = num;; i++)
    {
        if (i % F == 0)
        {
            num = i;
            break;
        }
    }
    int answer = num % 100;
    if (answer < 10)
        cout << "0" << answer << endl;
    else
        cout << answer << endl;
    return 0;
}