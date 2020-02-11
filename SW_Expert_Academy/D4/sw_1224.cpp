/*
난이도 : D4
문제 번호 : 1224
문제 제목 : 계산기3
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int length, A, B, tmp;
    string expression;
    stack<int> intStack;
    stack<char> symbolStack;
    queue<char> charQ;

    for (int i = 0; i < 10; i++)
    {
        int answer = 0;
        cin >> length;
        cin >> expression;

        for (int j = 0; j < length; j++)
        {
            if (expression[j] >= 48 && expression[j] <= 57)
                charQ.push(expression[j]);
            else if (expression[j] == ')')
            {
                while (symbolStack.top() != '(')
                {
                    charQ.push(symbolStack.top());
                    symbolStack.pop();
                }
                symbolStack.pop();
            }
            else //+ - 43, * - 42
            {
                if (!symbolStack.empty())
                {
                    if (symbolStack.top() == '(' || symbolStack.top() > expression[j])
                    {
                        symbolStack.push(expression[j]);
                    }
                    else
                    {
                        while (!symbolStack.empty() && symbolStack.top() != '(' && symbolStack.top() <= expression[j])
                        {
                            tmp = symbolStack.top();
                            symbolStack.pop();
                            charQ.push(tmp);
                        }

                        symbolStack.push(expression[j]);
                    }
                }
                else
                {
                    symbolStack.push(expression[j]);
                }
            }
        }
        while (!symbolStack.empty())
        {
            tmp = symbolStack.top();
            symbolStack.pop();
            charQ.push(tmp);
        }
        while (!charQ.empty())
        {
            char tmp = charQ.front();
            charQ.pop();
            if (tmp >= 48 && tmp <= 57)
                intStack.push((int)(tmp - 48));
            else
            {
                A = intStack.top();
                intStack.pop();
                B = intStack.top();
                intStack.pop();
                if (tmp == '*')
                    intStack.push(A * B);
                else
                    intStack.push(A + B);
            }
        }
        cout << "#" << (i + 1) << " " << intStack.top() << endl;
        intStack.pop();
    }
    return 0;
}
