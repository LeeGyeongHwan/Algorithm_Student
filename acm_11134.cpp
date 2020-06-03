/* 
ACMICPC 
문제 번호 : 11134
문제 제목 : 쿠키애호가
풀이 날짜 : 2020-06-03
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, N, C, answer;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> N >> C;

        answer = N / C;
        if (N % C != 0)
            answer++;
        cout << answer << endl;
    }
    return 0;
}