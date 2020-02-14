/*
난이도 : D3
문제 번호 : 7510
문제 제목 : 상원이의 연속 합
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, num;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int count = 0;
        cin >> num;
        for (int j = (num + 1) / 2; j >= 2; j--)
        {
            int tmp = j;
            int sum = 0;
            while (sum < num)
            {
                sum += tmp--;
            }
            if (sum == num)
                count++;
        }
        cout << "#" << (i + 1) << " " << count + 1 << endl;
    }
    return 0;
}