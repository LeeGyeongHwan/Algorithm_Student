/*
난이도 : D3
문제 번호 : 1218
문제 제목 : 괄호 짝짓기
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int length;
    string str;
    stack<char> charStack;
    for (int i = 0; i < 10; i++)
    {
        bool isValid = true;
        cin >> length;
        cin >> str;
        for (int j = 0; j < length; j++)
        {
            if (str[j] == '{' || str[j] == '[' || str[j] == '(' || str[j] == '<')
            {
                charStack.push(str[j]);
            }
            else
            {
                char compareChar = charStack.top();
                if (compareChar == '{' && str[j] == '}')
                    charStack.pop();
                else if (compareChar == '[' && str[j] == ']')
                    charStack.pop();
                else if (compareChar == '<' && str[j] == '>')
                    charStack.pop();
                else if (compareChar == '(' && str[j] == ')')
                    charStack.pop();

                else
                {
                    isValid = false;
                    break;
                }
            }
        }

        cout << "#" << (i + 1) << " " << isValid << endl;
    }
    return 0;
}