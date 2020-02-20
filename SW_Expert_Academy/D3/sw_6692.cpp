/*
난이도 : D3
문제 번호 : 6692
문제 제목 : 다솔이의 월급 상자
풀이 날짜 : 2020-02-20
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, num, money;
    double percent;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        double total = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> percent >> money;
            total += percent * money;
        }
        cout << fixed;
        cout.precision(6);
        cout << "#" << (i + 1) << " " << total << "\n";
    }

    return 0;
}