/*
난이도 : D2
문제 번호 : 1285
문제 제목 : 아름이의 돌 던지기
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, people, tmp;
    vector<int> intVec;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int minus = -100001, count = 0, answer;
        int nearToZero = 100001;

        cin >> people;
        for (int j = 0; j < people; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        sort(intVec.begin(), intVec.end());

        for (int j = 0; j < people; j++)
        {
            if (intVec[j] < 0)
            {
                minus = intVec[j];
            }
            else
            {
                if (intVec[j] < nearToZero)
                    nearToZero = intVec[j];
            }
        }

        answer = abs(minus) > abs(nearToZero) ? abs(nearToZero) : abs(minus);
        for (int j = 0; j < people; j++)
        {
            if (intVec[j] >= 0 - answer && intVec[j] <= answer)
                count++;
        }

        cout << "#" << (i + 1) << " " << answer << " " << count << endl;
        intVec.clear();
    }
    return 0;
}
