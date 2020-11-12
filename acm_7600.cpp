/*
ACMICPC
문제 번호 : 7600
문제 제목 : 문자가 몇갤까
풀이 날짜 : 2020-11-13
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string str;
    bool alpha[26];
    while (true)
    {
        getline(cin, str);
        if (!str.compare("#"))
            break;
        int size = str.length();
        for (int i = 0; i < size; i++)
        {
            char tmp = str[i];
            if (tmp - 'a' >= 0 && tmp - 'a' < 26)
                alpha[tmp - 'a'] = true;
            else if (tmp - 'A' >= 0 && tmp - 'A' < 26)
                alpha[tmp - 'A'] = true;
        }
        int cnt = 0;
        for (int j = 0; j < 26; j++)
            if (alpha[j])
                cnt++;
        cout << cnt << "\n";
        memset(alpha, 0, sizeof(alpha));
    }
    return 0;
}