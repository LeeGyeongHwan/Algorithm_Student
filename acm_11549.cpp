/*
ACMICPC
문제 번호 : 11549
문제 제목 : Identifying tea
풀이 날짜 : 2020-07-23
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int tea, num;
    int answer = 0;

    cin >> tea;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        if (num == tea)
            answer++;
    }

    cout << answer << endl;

    return 0;
}