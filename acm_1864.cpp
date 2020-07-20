/*
ACMICPC
문제 번호 : 1864
문제 제목 : 문어 숫자
풀이 날짜 : 2020-07-20
Solved By Reamer
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string octNum;

    while (1)
    {
        int originalNum = 0;
        cin >> octNum;
        if (octNum == "#")
            break;

        int multiNum = 1;
        for (int i = octNum.length() - 1; i >= 0; i--)
        {
            int charNum;
            if (octNum[i] == '-')
                charNum = 0;
            else if (octNum[i] == '\\')
                charNum = 1;
            else if (octNum[i] == '(')
                charNum = 2;
            else if (octNum[i] == '@')
                charNum = 3;
            else if (octNum[i] == '?')
                charNum = 4;
            else if (octNum[i] == '>')
                charNum = 5;
            else if (octNum[i] == '&')
                charNum = 6;
            else if (octNum[i] == '%')
                charNum = 7;
            else if (octNum[i] == '/')
                charNum = -1;

            originalNum += charNum * multiNum;
            multiNum *= 8;
        }
        cout << originalNum << endl;
    }

    return 0;
}