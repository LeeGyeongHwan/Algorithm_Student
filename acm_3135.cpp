/*
ACMICPC
문제 번호 : 3135
문제 제목 : 라디오
풀이 날짜 : 2020-07-12
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B;
    int N, hz;

    cin >> A >> B;
    int minBtn = abs(A - B);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> hz;
        int tmp = abs(hz - B) + 1;
        if (minBtn > tmp)
            minBtn = tmp;
    }

    cout << minBtn << endl;

    return 0;
}