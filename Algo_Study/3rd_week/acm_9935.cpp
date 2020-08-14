/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 9935
문제 제목 : 문자열 폭발 
풀이 날짜 : 2020-08-14
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string oriStr, boomStr;
    stack<char> tmpStack;
    deque<char> answer;
    vector<pair<int, int>> pairVec;
    cin >> oriStr >> boomStr;

    int boomCount = boomStr.length() - 1;

    for (int i = 0; i < oriStr.length(); i++)
    {
        int boomCount = boomStr.length() - 1;
        int tmpChar = oriStr[i];
        if (tmpChar == boomStr[boomCount])
        {
            tmpStack.push(tmpChar);
            boomCount--;
            for (int i = 0; i < boomStr.length() - 1; i++)
            {
                if (!answer.empty() && answer.back() == boomStr[boomCount])
                {
                    boomCount--;
                    tmpStack.push(answer.back());
                    answer.pop_back();
                }
            }
            if (tmpStack.size() == boomStr.length())
            {
                while (!tmpStack.empty())
                {
                    tmpStack.pop();
                }
            }
            else
            {
                while (!tmpStack.empty())
                {
                    answer.push_back(tmpStack.top());
                    tmpStack.pop();
                }
            }
        }
        else
        {
            answer.push_back(oriStr[i]);
        }
    }

    if (answer.empty())
    {
        cout << "FRULA\n";
    }
    else
    {
        while (!answer.empty())
        {
            char tmp = answer.front();
            answer.pop_front();
            cout << tmp;
        }
    }

    return 0;
}