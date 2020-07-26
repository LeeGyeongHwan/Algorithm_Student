/* 
ACMICPC 
문제 번호 : 10406
문제 제목 : The fellowship of the ring
풀이 날짜 : 2020-07-26
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int waist, height, punch, num;
    int answer = 0;

    cin >> waist >> height >> punch;

    for (int i = 0; i < punch; i++)
    {
        cin >> num;

        if (num >= waist && num <= height)
            answer++;
    }
    cout << answer << endl;

    return 0;
}