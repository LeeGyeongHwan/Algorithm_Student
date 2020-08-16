/*
ACMICPC
문제 번호 : 5430
문제 제목 : AC 
풀이 날짜 : 2020-08-16
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase, num;
    string operation, numStr;
    deque<int> AC;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> operation;
        cin >> num;
        cin >> numStr;

        int leftD = 0;
        int rightD = 0;
        bool isLeft = true;
        for (int j = 0; j < operation.length(); j++)
        {
            if (operation[j] == 'R')
            {
                isLeft = !isLeft;
            }
            else
            {
                if (isLeft)
                    leftD++;
                else
                    rightD++;
            }
        }
        if (num == 0)
        {
            if (leftD == 0 && rightD == 0)
                cout << "[]\n";
            else
                cout << "error\n";
            continue;
        }
        bool numStart = false;
        int idx = 0;
        for (int j = 0; j < numStr.length(); j++)
        {
            if (numStr[j] == ',')
            {
                string tmp = numStr.substr(idx, j - idx);
                AC.push_back(stoi(tmp));
                numStart = false;
            }
            else if (numStr[j] == '[')
            {
            }
            else if (numStr[j] == ']')
            {
                string tmp = numStr.substr(idx, j - idx);
                AC.push_back(stoi(tmp));
                numStart = false;
            }
            else
            {
                if (!numStart)
                {
                    numStart = true;
                    idx = j;
                }
            }
        }
        bool isError = false;
        for (int j = 0; j < leftD; j++)
        {
            if (!AC.empty())
                AC.pop_front();
            else
            {
                isError = true;
                break;
            }
        }
        for (int j = 0; j < rightD; j++)
        {
            if (!AC.empty())
                AC.pop_back();
            else
            {
                isError = true;
                break;
            }
        }
        if (isError)
            cout << "error\n";
        else
        {
            string answ = "[";
            if (isLeft)
            {

                int size = AC.size();
                for (int j = 0; j < size; j++)
                {
                    answ += to_string(AC.front());
                    if (j != size - 1)
                        answ += ",";
                    AC.pop_front();
                }
            }
            else
            {
                int size = AC.size();
                for (int j = 0; j < size; j++)
                {
                    answ += to_string(AC.back());
                    if (j != size - 1)
                        answ += ",";
                    AC.pop_back();
                }
            }
            answ += "]";
            cout << answ << "\n";
        }
        AC.clear();
    }
    return 0;
}