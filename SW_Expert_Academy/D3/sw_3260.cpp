/*
난이도 : D3
문제 번호 : 3260
문제 제목 : 두 수의 덧셈
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    string numA, numB;
    char charA, charB;
    stack<char> charStack;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int isOver = 0;
        cin >> numA >> numB;
        int sizeA = numA.size();
        int sizeB = numB.size();
        int length = sizeA < sizeB ? sizeA : sizeB;
        for (int j = 1; j <= length; j++)
        {
            charA = numA[sizeA - j];
            charB = numB[sizeB - j];
            int tmp = (int)(charA - 48) + (int)(charB - 48) + isOver;
            if (tmp >= 10)
            {
                tmp -= 10;
                isOver = 1;
            }
            else
                isOver = 0;
            charStack.push(char(48 + tmp));
        }

        if (sizeA < sizeB)
        {
            for (int j = sizeA; j < sizeB; j++)
            {
                charB = numB[sizeB - j - 1];
                if (isOver)
                {
                    int tmp = (int)(charB - 48) + isOver;
                    if (tmp >= 10)
                    {
                        tmp -= 10;
                        isOver = 1;
                    }
                    else
                        isOver = 0;
                    charStack.push(char(48 + tmp));
                }
                else
                {
                    charStack.push(charB);
                }
            }
        }
        else if (sizeA == sizeB)
        {
            if (isOver == 1)
                charStack.push(49);
        }
        else
        {
            for (int j = sizeB; j < sizeA; j++)
            {
                charA = numA[sizeA - j - 1];
                if (isOver)
                {
                    int tmp = (int)(charA - 48) + isOver;
                    if (tmp >= 10)
                    {
                        tmp -= 10;
                        isOver = 1;
                    }
                    else
                        isOver = 0;
                    charStack.push(char(48 + tmp));
                }
                else
                {
                    charStack.push(charA);
                }
            }
        }

        if(isOver)
             charStack.push(49);

        cout << "#" << (i + 1) << " ";
        while (!charStack.empty())
        {
            cout << charStack.top();
            charStack.pop();
        }
        cout << endl;
    }
    return 0;
}