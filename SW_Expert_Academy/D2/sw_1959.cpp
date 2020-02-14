/*
난이도 : D2
문제 번호 : 1959
문제 제목 : 두 개의 숫자열
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, M, tmp;
    vector<int> vecA, vecB;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int maxNum = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            vecA.push_back(tmp);
        }
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            vecB.push_back(tmp);
        }

        if (vecA.size() > vecB.size())
        {
            for (int j = 0; j <= vecA.size() - vecB.size(); j++)
            {
                int sumNum = 0;
                for (int k = 0; k < vecB.size(); k++)
                {
                    sumNum += vecA[j + k] * vecB[k];
                }
                if (maxNum < sumNum)
                    maxNum = sumNum;
            }
        }
        else
        {
            for (int j = 0; j <= vecB.size() - vecA.size(); j++)
            {
                int sumNum = 0;
                for (int k = 0; k < vecA.size(); k++)
                {
                    sumNum += vecA[k] * vecB[j + k];
                }
                if (maxNum < sumNum)
                    maxNum = sumNum;
            }
        }

        cout << "#" << (i + 1) << " " << maxNum << endl;
        vecA.clear();
        vecB.clear();
    }
    return 0;
}
