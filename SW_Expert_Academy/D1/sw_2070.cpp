/*
난이도 : D1
문제 번호 : 2070
문제 제목 : 큰 놈, 작은 놈, 같은 놈
풀이 날짜 : 2020-02-02
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, tmp;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int A, B;
        char equality;
        cin >> A >> B;

        if (A > B)
            equality = '>';
        else if (A < B)
            equality = '<';
        else
            equality = '=';
        cout << "#" << (i + 1) << " " << equality << endl;
    }
    return 0;
}