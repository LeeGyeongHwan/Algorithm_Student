/*
난이도 : D3
문제 번호 : 8931
문제 제목 : 제로
풀이 날짜 : 2020-01-31
Solved By Reamer
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int testCase, numK, tmp;
    string testStr;
    stack<int> intStack;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int testSum = 0;
        cin >> numK;
        for (int j = 0; j < numK; j++)
        {
            cin >> tmp;
            if (tmp == 0)
                intStack.pop();
            else
                intStack.push(tmp);
        }

        while (!intStack.empty())
        {
            testSum += intStack.top();
            intStack.pop();
        }

        cout << "#" << (i + 1) << " " << testSum << endl;
    }
    return 0;
}