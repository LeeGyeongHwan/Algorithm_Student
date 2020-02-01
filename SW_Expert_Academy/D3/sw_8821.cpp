/*
난이도 : D3
문제 번호 : 8821
문제 제목 : 적고 지우기
풀이 날짜 : 2020-02-01
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int testCase;
    string num;
    bool isCheck[10] = {0};
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        for(int j=0;j<num.length();j++)
        {
            int convertedNum = (int)num[j] - 48;
            if (isCheck[convertedNum])
                isCheck[convertedNum] = false;
            else
                isCheck[convertedNum] = true;
        }
        int sum = 0;
        for (int j = 0; j < 10; j++)
        {
            if (isCheck[j])
                sum++;
        }

        cout << "#" << (i + 1) << " " << sum << endl;
        memset(isCheck, 0, sizeof(isCheck));
    }
    return 0;
}