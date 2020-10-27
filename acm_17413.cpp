/*
ACMICPC
문제 번호 : 17413
문제 제목 : 단어 뒤집기 2
풀이 날짜 : 2020-10-28
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> strVec;
    vector<char> charVec;
    stack<char> charS;
    getline(cin, str);

    bool isTag = false;
    string tmp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isTag)
        {
            tmp += str[i];
            if (str[i] == '>')
            {
                charVec.push_back('S');
                strVec.push_back(tmp);
                tmp = "";
                isTag = false;
            }
        }
        else
        {
            if (str[i] == '<')
            {
                tmp += str[i];
                isTag = true;
            }
            else
                charVec.push_back(str[i]);
        }
    }
    int vCnt = 0;
    for (int i = 0; i < charVec.size(); i++)
    {
        if (charVec[i] == 'S')
        {
            while (!charS.empty())
            {
                cout << charS.top();
                charS.pop();
            }
            cout << strVec[vCnt++];
        }
        else if (charVec[i] == ' ')
        {
            while (!charS.empty())
            {
                cout << charS.top();
                charS.pop();
            }
            cout << " ";
        }
        else
        {
            charS.push(charVec[i]);
        }
    }
    while (!charS.empty())
    {
        cout << charS.top();
        charS.pop();
    }

    return 0;
}