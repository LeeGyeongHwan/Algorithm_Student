/* 
ACMICPC
Study Group
4th Week
문제 번호 : 1662
문제 제목 : 압축
풀이 날짜 : 2020-08-21
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
    cout.tie(NULL);
    string str;

    stack<char> charS;
    stack<int> specialS;
    cin >> str;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ')')
        {
            int count = 0;
            while (charS.top() != '(')
            {
                if (charS.top() == 's')
                {
                    count += specialS.top();
                    specialS.pop();
                }
                else
                    count++;
                charS.pop();
            }

            charS.pop();
            if (charS.top() == 's')
            {
                int tmpTop = specialS.top();
            }
            else
                specialS.push((charS.top() - '0') * count);
            charS.pop();
            charS.push('s');
        }
        else
        {
            charS.push(str[i]);
        }
    }
    int answer = 0;
    while (!charS.empty())
    {
        char tmp = charS.top();
        charS.pop();
        if (tmp == 's')
        {
            answer += specialS.top();
            specialS.pop();
        }
        else
            answer++;
    }
    cout << answer << "\n";
    return 0;
}