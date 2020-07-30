/*
난이도 : D3
문제 번호 : 9700
문제 제목 : USB 꽂기의 미스터리
풀이 날짜 : 2020-07-30
Solved By Reamer
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        double p, q;
        cin >> p >> q;

        double s1 = (1 - p) * q;
        double s2 = p * (1 - q) * q;

        if (s1 < s2)
            cout << "#" << i + 1 << " YES" << endl;
        else
            cout << "#" << i + 1 << " NO" << endl;
    }

    return 0;
}