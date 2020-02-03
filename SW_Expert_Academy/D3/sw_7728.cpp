/*
난이도 : D3
문제 번호 : 7728
문제 제목 : 다양성 측정
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int testCase, num;
    bool isCheck[10] = {0};
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int diversity = 0;
        cin >> num;
        do
        {
            isCheck[num % 10] = true;
            num /= 10;
        } while (num != 0);
        for (int j = 0; j < 10; j++)
        {
            if (isCheck[j])
                diversity++;
        }
        cout << "#" << (i + 1) << " " << diversity << endl;
        memset(isCheck, 0, sizeof(isCheck));
    }
    return 0;
}