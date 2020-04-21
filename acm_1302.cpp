/*
ACMICPC
문제 번호 : 1302
문제 제목 : 베스트셀러 
풀이 날짜 : 2020-04-21
Solved By Reamer
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int num;
    int maxNum = 0;
    string str;
    map<string, int> bookMap;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> str;
        bookMap[str]++;
    }

    for (auto i = bookMap.begin(); i != bookMap.end(); i++)
    {
        maxNum = maxNum > i->second ? maxNum : i->second;
    }

    for (auto i = bookMap.begin(); i != bookMap.end(); i++)
    {
        if (maxNum == i->second)
        {
            cout << i->first;
            return 0;
        }
    }

    return 0;
}