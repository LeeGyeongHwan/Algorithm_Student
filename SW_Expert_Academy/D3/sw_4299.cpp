/*
난이도 : D3
문제 번호 : 4299
문제 제목 : 태혁이의 사랑은 타이밍
풀이 날짜 : 2020-02-21
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, D, H, M;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int totalSum = 0;
        cin >> D >> H >> M;

        if (M < 11)
        {
            H--;
            M += 60;
        }
        totalSum += M - 11;
        if (H < 11)
        {
            D--;
            H += 24;
        }
        totalSum += (H - 11) * 60 + (D - 11) * 24 * 60;

        if (totalSum < 0)
            cout << "#" << (i + 1) << " -1\n";
        else
            cout << "#" << (i + 1) << " " << totalSum << "\n";
    }

    return 0;
}