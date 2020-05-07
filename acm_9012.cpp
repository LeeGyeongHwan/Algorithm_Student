/*
ACMICPC
문제 번호 : 9012
문제 제목 : 괄호
풀이 날짜 : 2020-05-07
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int num;
    string str;
    vector<string> strVec;
    stack<char> charStack;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> str;
        strVec.push_back(str);
    }

    for (int i = 0; i < strVec.size(); i++)
    {
        bool isRight = true;
        for (int j = 0; j < strVec[i].length(); j++)
        {
            if (strVec[i][j] == '(')
            {
                charStack.push('(');
            }
            else
            {
                if (!charStack.empty() && charStack.top() == '(')
                {
                    charStack.pop();
                }
                else
                {
                    isRight = false;
                    break;
                }
            }
        }
        if (!charStack.empty())
        {
            isRight = false;
            while (!charStack.empty())
                charStack.pop();
        }

        if (isRight)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}