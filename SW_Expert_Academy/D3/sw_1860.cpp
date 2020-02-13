/*
난이도 : D3
문제 번호 : 1860
문제 제목 : 진기의 최고급 붕어빵
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int testCase, people, time, bread, tmp;
    vector<int> intVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        bool isPossible = true;
        cin >> people >> time >> bread;

        for (int j = 0; j < people; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());

        for (int j = 0; j < people; j++)
        {
            if (intVec[j] / time * bread - (j + 1) < 0)
            {
                isPossible = false;
                break;
            }
        }

        if (isPossible)
            cout << "#" << (i + 1) << " Possible" << endl;
        else
            cout << "#" << (i + 1) << " Impossible" << endl;

        intVec.clear();
    }
    return 0;
}