/*
난이도 : D2
문제 번호 : 1989
문제 제목 : 초심자의 회문 검사
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, tmp;
    string testStr;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int isPalindrome = 1;
        cin >> testStr;

        for (int j = 0; j <= testStr.length() / 2 - 1; j++)
        {
            if (testStr[j] != testStr[testStr.length() - j - 1])
            {
                isPalindrome = 0;
                break;
            }
        }
        cout << "#" << (i + 1) << " " << isPalindrome << endl;
    }
    return 0;
}