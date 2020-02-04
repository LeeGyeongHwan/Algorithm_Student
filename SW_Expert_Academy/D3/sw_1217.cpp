/*
난이도 : D3
문제 번호 : 1217
문제 제목 : 거듭 제곱
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
using namespace std;

int exponentialFunc(int N, int M)
{
    if (M == 1)
        return N;
    else
    {
        return N * exponentialFunc(N, M - 1);
    }
}

int main()
{
    int testCase, N, M, result;
    for (int i = 0; i < 10; i++)
    {

        cin >> testCase;
        cin >> N >> M;

        result = exponentialFunc(N, M);

        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}