/*
난이도 : D3
문제 번호 : 6718
문제 제목 : 희성이의 원근법
풀이 날짜 : 2020-02-20
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, distance;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int count = 0, divide = 100;

        cin >> distance;
        while (distance / divide != 0)
        {
            count++;
            distance /= divide;
            divide = 10;
        }
        if (count > 5)
            count = 5;
        cout << "#" << (i + 1) << " " << count << "\n";
    }

    return 0;
}