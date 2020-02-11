/*
난이도 : D2
문제 번호 : 1976
문제 제목 : 시각 덧셈
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, firstH, firstM, secondH, secondM;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int finalH = 0, finalM;
        cin >> firstH >> firstM >> secondH >> secondM;
        finalM = firstM + secondM;
        if (finalM >= 60)
        {
            finalM -= 60;
            finalH++;
        }
        finalH += firstH + secondH;
        if (finalH > 12)
            finalH -= 12;
        cout << "#" << (i + 1) << " " << finalH << " " << finalM << endl;
    }

    return 0;
}