/*
난이도 : D3
문제 번호 : 2805
문제 제목 : 농작물 수확하기
풀이 날짜 : 2020-03-11
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num;
    int farm[50][50];
    char tmp;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int total = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                cin >> tmp;
                farm[j][k] = tmp - '0';
            }
        }
        int border = num / 2;
        for (int j = 0; j < num; j++)
        {
            if (j < border)
            {
                for (int k = border - j; k <= border + j; k++)
                {
                    total += farm[j][k];
                }
            }
            else
            {
                for (int k = border - (num - j - 1); k <= border + num - j - 1; k++)
                {
                    total += farm[j][k];
                }
            }
        }

        cout << "#" << (i + 1) << " " << total << endl;
    }
    return 0;
}