/*
난이도 : D3
문제 번호 : 3142
문제 제목 : 영준이와 신비한 뿔의 숲
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, horn, number;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> horn >> number;
        cout << "#" << (i + 1) << " " << number * 2 - horn << " " << horn - number << endl;
    }

    return 0;
}