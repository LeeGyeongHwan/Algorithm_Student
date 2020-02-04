/*
난이도 : D2
문제 번호 : 2001
문제 제목 : 파리 퇴치
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testCase, N, M, tmp;
    vector<vector<int>> intVV;
    vector<int> tmpVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxKill = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVV.push_back(tmpVec);
            tmpVec.clear();
        }
        for (int i1 = 0; i1 <= N - M; i1++)
        {

            for (int j1 = 0; j1 <= N - M; j1++)
            {
                int tmpKill = 0;
                for (int i2 = i1; i2 < i1 + M; i2++)
                {
                    for (int j2 = j1; j2 < j1 + M; j2++)
                    {
                        tmpKill += intVV[i2][j2];
                    }
                }
                if (tmpKill > maxKill)
                    maxKill = tmpKill;
            }
        }

        cout << "#" << (i + 1) << " " << maxKill << endl;
        intVV.clear();
    }
    return 0;
}