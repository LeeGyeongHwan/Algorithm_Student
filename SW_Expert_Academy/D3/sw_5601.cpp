/*
난이도 : D3
문제 번호 : 5601
문제 제목 : 쥬스 나누기   
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, people;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> people;

        cout << "#" << (i + 1);

        for (int j = 0; j < people; j++)
            cout << " " << "1/" << people;
        cout << endl;
    }
    return 0;
}