/*
난이도 : D3
문제 번호 : 7087
문제 제목 : 문제 제목 붙이기
풀이 날짜 : 2020-02-19
Solved By Reamer
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N;
    string title;
    int titleArr[26] = {0};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int answer = 26;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> title;
            titleArr[(int)(title[0] - 'A')]++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (titleArr[j] == 0)
            {
                answer = j;
                break;
            }
        }
        cout << "#" << (i + 1) << " " << answer << "\n";
        memset(titleArr, 0, sizeof(titleArr));
    }
    return 0;
}