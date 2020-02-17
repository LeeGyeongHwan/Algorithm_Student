/*
난이도 : D3
문제 번호 : 3314
문제 제목 : 보충학습과 평균
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int score = 0;
        for (int j = 0; j < 5; j++)
        {
            cin >> tmp;
            if (tmp < 40)
                score += 40;
            else
                score += tmp;
        }
        cout << "#" << (i + 1) << " " << score / 5 << endl;
    }
    return 0;
}