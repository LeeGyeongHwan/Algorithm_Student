/*
ACMICPC
문제 번호 : 1057
문제 제목 : 토너먼트
풀이 날짜 : 2020-03-13
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int people, A, B;
    int count = 1;
    cin >> people >> A >> B;

    while (1)
    {
        //cout << "A : " << A << ", B: " << B << ", count : " << count << ", people : " << people << endl;
        if ((A + 1) / 2 == (B + 1) / 2)
            break;

        A = (A + 1) / 2;
        B = (B + 1) / 2;

        people = people / 2 + people % 2;
        count++;
    }

    cout << count << endl;
    return 0;
}