/*
난이도 : D1
문제 번호 : 2029
문제 제목 : 몫과 나머지 출력하기
풀이 날짜 : 2020-02-09
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> A >> B;
        cout << "#" << (i + 1) << " " << A / B << " " << A % B << endl;
    }

    return 0;
}