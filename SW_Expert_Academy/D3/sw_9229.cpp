/*
난이도 : D3
문제 번호 : 9229
문제 제목 : 한빈이와 Spot Mart
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, num, limit, tmp;
    vector<int> intVec;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int maxWeight = -1;
        cin >> num >> limit;

        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());
        for (int j = 0; j < num - 1; j++)
        {
            for (int k = j + 1; k < num; k++)
            {
                tmp = intVec[j] + intVec[k];
                if (tmp > limit)
                    break;
                if (tmp > maxWeight)
                    maxWeight = tmp;
            }
        }
        cout << "#" << (i + 1) << " " << maxWeight << "\n";
        intVec.clear();
    }
    return 0;
}