/*
난이도 : D2
문제 번호 : 1284
문제 제목 : 수도 요금 경쟁
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, P, Q, R, S, W;
    int costA, costB;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> P >> Q >> R >> S >> W;
        costA = P * W;
        if (R > W)
            costB = Q;
        else
            costB = Q + (W - R) * S;

        if (costA > costB)
            cout << "#" << (i + 1) << " " << costB << endl;
        else
            cout << "#" << (i + 1) << " " << costA << endl;
    }
    return 0;
}