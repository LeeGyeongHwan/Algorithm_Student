/*
난이도 : D2
문제 번호 : 1948
문제 제목 : 날짜 계산기
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, startMonth, startDay, endMonth, endDay;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int totalDay = 0;
        cin >> startMonth >> startDay >> endMonth >> endDay;

        if (startMonth == endMonth)
            totalDay = endDay - startDay + 1;
        else
        {
            for (int j = startMonth; j < endMonth; j++)
            {
                if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
                    totalDay += 31;
                else if (j == 2)
                    totalDay += 28;
                else
                    totalDay += 30;
            }
            totalDay = totalDay - startDay + endDay + 1;
        }

        cout << "#" << (i + 1) << " " << totalDay << endl;
    }
    return 0;
}
