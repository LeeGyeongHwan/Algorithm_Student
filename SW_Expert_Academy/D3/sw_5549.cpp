/*
난이도 : D3
문제 번호 : 5549
문제 제목 : 홀수일까 짝수일까
풀이 날짜 : 2020-02-21
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    string str;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        string answer;
        cin >> str;

        int lastWord = str[str.length()-1]-'0';
        if(lastWord%2==0)
            answer="Even";
        else
            answer="Odd";

        cout << "#" << (i + 1) << " " << answer << "\n";
    }

    return 0;
}