/*
ACMICPC
문제 번호 : 3040
문제 제목 : 백설 공주와 일곱 난쟁이
풀이 날짜 : 2020-11-07
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int people[9];
int removed[2];

void removeTwo(int cnt, int start, int sum)
{
    if (cnt == 2)
    {
        if (sum == 100)
        {
            vector<int> intVec;
            int idx = 0;
            for (int i = 0; i < 9; i++)
            {
                if (idx < 2 && removed[idx] == i)
                {
                    idx++;
                }
                else
                {
                    intVec.push_back(people[i]);
                }
            }
            sort(intVec.begin(), intVec.end());
            for (int i = 0; i < intVec.size(); i++)
                cout << intVec[i] << "\n";
            exit(0);
        }

        return;
    }

    for (int i = start; i < 9; i++)
    {
        removed[cnt] = i;
        removeTwo(cnt + 1, start + 1, sum - people[i]);
    }
}

int main()
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> people[i];
        total += people[i];
    }

    removeTwo(0, 0, total);
    return 0;
}