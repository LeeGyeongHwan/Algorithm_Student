/*
난이도 : D3
문제 번호 : 10200
문제 제목 : 구독자 전쟁
풀이 날짜 : 2020-07-29
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    int N, A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxP = 0, minP = 0;
        cin >> N >> A >> B;

        maxP = A > B ? B : A;
        if (A + B > N)
            minP = A + B - N;

        cout << "#" << i + 1 << " " << maxP << " " << minP << endl;
    }
    return 0;
}