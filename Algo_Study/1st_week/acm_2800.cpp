/* 
ACMICPC
Study Group
1st Week
문제 번호 : 2800
문제 제목 : 괄호 제거
풀이 날짜 : 2020-08-02
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

vector<string> answerVec;
vector<pair<int, int>> bracketVec;
vector<int> indexVec;
string str;
bool isVisit[10];
int num;

void findOp(int count)
{
    if (count == num)
    {
        for (int i = 0; i < num; i++)
        {
            if (isVisit[i]) // 추가
            {
                int x, y;
                tie(x, y) = bracketVec[i];
                indexVec.push_back(x);
                indexVec.push_back(y);
            }
        }
        if (indexVec.size() != 0)
        {
            sort(indexVec.begin(), indexVec.end());
            int index = 0;
            string tmp = "";
            for (int i = 0; i < str.length(); i++)
            {
                if (i == indexVec[index])
                {
                    index++;
                }
                else
                    tmp += str[i];
            }
            answerVec.push_back(tmp);
            indexVec.clear();
        }
        return;
    }

    isVisit[count] = true;
    findOp(count + 1);
    isVisit[count] = false;
    findOp(count + 1);
}

int main()
{
    stack<int> intS;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            intS.push(i);
        else if (str[i] == ')')
        {
            int tmp = intS.top();
            intS.pop();
            bracketVec.push_back(make_pair(tmp, i));
        }
    }
    num = bracketVec.size();

    findOp(0);

    sort(answerVec.begin(), answerVec.end());
    if (answerVec.size() != 0)
    {
        cout << answerVec.front() << "\n";
        if (answerVec.size() > 1)
        {
            for (int i = 1; i < answerVec.size(); i++)
            {
                if (answerVec[i - 1] == answerVec[i])
                    continue;
                cout << answerVec[i] << endl;
            }
        }
    }

    return 0;
}