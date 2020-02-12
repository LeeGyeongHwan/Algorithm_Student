/*
난이도 : D2
문제 번호 : 1288
문제 제목 : 새로운 불면증 치료법
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, tmp;
    bool isCheck[10] = {0};
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        bool isAllCount = false;
        int count;
        cin >> N;

        for (int j = N;; j += N)
        {
            tmp = j;
            while (tmp != 0)
            {
                isCheck[tmp % 10] = true;
                tmp /= 10;
            }

            for (int k = 0; k < 10; k++)
            {
                if (!isCheck[k])
                {
                    isAllCount = false;
                    break;
                }
                if (k == 9 && isCheck[9])
                    isAllCount = true;
            }
            if (isAllCount)
            {
                count = j;
                break;
            }
        }

        cout << "#" << (i + 1) << " " << count << endl;
        memset(isCheck, 0, sizeof(isCheck));
    }
    return 0;
}
