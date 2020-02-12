/*
난이도 : D3
문제 번호 : 3431
문제 제목 : 준환이의 운동관리
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, L, U, X;
    bool isCheck[10] = {0};
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int answer;
        cin >> L >> U >> X;

        if (X > U)
            answer = -1;
        else if (X < L)
        {
            answer = L - X;
        }
        else
            answer = 0;

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}
