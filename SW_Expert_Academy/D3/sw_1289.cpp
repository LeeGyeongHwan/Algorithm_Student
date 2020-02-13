/*
난이도 : D3
문제 번호 : 1289
문제 제목 : 원재의 메모리 복구하기
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    string str;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int count = 0;
        bool isOneContinue = false;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (!isOneContinue && str[j] == '1')
            {
                count++;
                isOneContinue = true;
            }
            else if (isOneContinue && str[j] == '0')
            {
                count++;
                isOneContinue = false;
            }
        }
        cout << "#" << (i + 1) << " " << count << endl;
    }
    return 0;
}