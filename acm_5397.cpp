/*
ACMICPC
문제 번호 : 5397
문제 제목 : 키로거
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    string str;
    stack<char> leftS, rightS;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '<')
            {
                if (!leftS.empty())
                {
                    rightS.push(leftS.top());
                    leftS.pop();
                }
            }
            else if (str[i] == '>')
            {
                if (!rightS.empty())
                {
                    leftS.push(rightS.top());
                    rightS.pop();
                }
            }
            else if (str[i] == '-')
            {
                if (!leftS.empty())
                    leftS.pop();
            }
            else
            {
                leftS.push(str[i]);
            }
        }

        while (!leftS.empty())
        {
            rightS.push(leftS.top());
            leftS.pop();
        }
        while (!rightS.empty())
        {
            cout << rightS.top();
            rightS.pop();
        }
        cout << "\n";
    }
    return 0;
}