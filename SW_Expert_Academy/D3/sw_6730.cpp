/*
난이도 : D3
문제 번호 : 6730
문제 제목 : 장애물 경주 난이도
풀이 날짜 : 2020-02-20
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, obstacle, tmp;
    vector<int> intVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxPlus = 0, maxMinus = 0;
        cin >> obstacle;
        for (int j = 0; j < obstacle; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        for (int j = 1; j < obstacle; j++)
        {
            tmp = intVec[j] - intVec[j - 1];
            if (tmp < maxMinus)
                maxMinus = tmp;
            if (tmp > maxPlus)
                maxPlus = tmp;
        }

        cout << "#" << (i + 1) << " " << maxPlus << " " << maxMinus * -1 << "\n";
        intVec.clear();
    }

    return 0;
}