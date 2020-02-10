/*
난이도 : D2
문제 번호 : 1945
문제 제목 : 간단한 소인수분해
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int count2 = 0, count3 = 0, count5 = 0;
        int count7 = 0, count11 = 0;
        cin >> num;

        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
                count2++;
            }
            else if (num % 3 == 0)
            {
                num /= 3;
                count3++;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
                count5++;
            }
            else if (num % 7 == 0)
            {
                num /= 7;
                count7++;
            }
            else if (num % 11 == 0)
            {
                num /= 11;
                count11++;
            }
        }

        cout << "#" << (i + 1) << " " << count2 << " " << count3
             << " " << count5 << " " << count7 << " " << count11 << endl;
    }
    return 0;
}