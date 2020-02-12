/*
난이도 : D3
문제 번호 : 1225
문제 제목 : 암호생성기 
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int testCase, num, tmp;
    queue<int> intQ;
    for (int i = 0; i < 10; i++)
    {
        cin >> testCase;
        for (int j = 0; j < 8; j++)
        {
            cin >> num;
            intQ.push(num);
        }

        for (int j = 1;; j++)
        {
            if (j % 5 == 0)
                tmp = intQ.front() - 5;
            else
                tmp = intQ.front() - j % 5;
            intQ.pop();
            if (tmp <= 0)
            {
                intQ.push(0);
                break;
            }
            intQ.push(tmp);
        }

        cout << "#" << testCase;
        while (!intQ.empty())
        {
            tmp = intQ.front();
            intQ.pop();
            cout << " " << tmp;
        }
        cout << endl;
    }
    return 0;
}