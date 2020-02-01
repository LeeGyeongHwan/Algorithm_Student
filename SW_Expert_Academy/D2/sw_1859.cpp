/*
난이도 : D2
문제 번호 : 1859
문제 제목 : 백만 장자 프로젝트
풀이 날짜 : 2020-02-01
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testCase, day, tmp;
    vector<int> intVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        long long benefit = 0;
        cin >> day;
        for (int j = 0; j < day; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        int buy = 0;
        long long cost = 0;
        int maxCost = intVec.back();
        for (int j = intVec.size() - 2; j >= 0; j--)
        {
            if (intVec[j] >= maxCost)
            {
                benefit += maxCost * buy - cost;
                maxCost = intVec[j];
                buy = 0;
                cost = 0;
            }
            else
            {
                cost += intVec[j];
                buy++;
            }
        }
        if (buy != 0)
        {
            benefit += maxCost * buy - cost;
        }

        cout << "#" << (i + 1) << " " << benefit << endl;
        intVec.clear();
    }
    return 0;
}