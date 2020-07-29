/*
난이도 : D3
문제 번호 : 10032
문제 제목 : 과자 분배
풀이 날짜 : 2020-07-29
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, N, K;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> N >> K;
        int answer = N % K == 0 ? 0 : 1;

        cout << "#" << i + 1 << " " << answer << endl;
    }
    return 0;
}
