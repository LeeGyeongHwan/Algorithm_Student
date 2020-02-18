/*
난이도 : D3
문제 번호 : 3750
문제 제목 : Digit sum
풀이 날짜 : 2020-02-18
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    long long num;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int sum = 0;
        cin >> num;
        do
        {
            sum = 0;
            while (num != 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        } while (sum >= 10);

        cout << "#" << (i + 1) << " " << sum << "\n";
    }

    return 0;
}