/*
난이도 : D4
문제 번호 : 1219
문제 제목 : 길찾기
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int route1[100] = {0};
    int route2[100] = {0};
    bool isCheck[100] = {0};

    int testCase, num, start, dest;

    for (int i = 0; i < 10; i++)
    {
        stack<int> intStack;
        bool isValid = false;
        cin >> testCase >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> start >> dest;
            if (route1[start] == 0)
                route1[start] = dest;
            else
                route2[start] = dest;
        }

        intStack.push(0);

        while (!intStack.empty())
        {
            int topNum = intStack.top();
            if (topNum == 99)
            {
                isValid = true;
            }
            int num1 = route1[topNum];
            int num2 = route2[topNum];

            if (num1 && isCheck[num1] == false)
            {
                isCheck[num1] = true;
                intStack.push(num1);
            }
            else if (num2 && isCheck[num2] == false)
            {
                isCheck[num2] = true;
                intStack.push(num2);
            }
            else
            {
                intStack.pop();
            }
        }

        cout << "#" << testCase << " " << isValid << endl;
        memset(route1, 0, sizeof(route1));
        memset(route2, 0, sizeof(route2));
        memset(isCheck, 0, sizeof(isCheck));
    }
    return 0;
}
