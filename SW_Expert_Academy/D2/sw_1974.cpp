/*
난이도 : D2
문제 번호 : 1974
문제 제목 : 스도쿠 검증
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;
    vector<vector<int>> intVV;
    vector<int> tmpVec;
    int grid[3][3] = {0};
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        bool isSudoku = true;
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVV.push_back(tmpVec);
            tmpVec.clear();
        }

        for (int j = 0; j < 9; j++)
        {
            int rowSum = 0;
            int colSum = 0;
            for (int k = 0; k < 9; k++)
            {
                rowSum += intVV[j].at(k);
                grid[j / 3][k / 3] += intVV[j].at(k);
                colSum += intVV[k].at(j);
            }
            if (rowSum != 45 || colSum != 45)
            {
                isSudoku = false;
                break;
            }
        }

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[j][k] != 45)
                {
                    isSudoku = false;
                    break;
                }
            }
        }
        cout << "#" << (i + 1) << " " << isSudoku << endl;
        intVV.clear();
        memset(grid, 0, sizeof(grid));
    }

    return 0;
}