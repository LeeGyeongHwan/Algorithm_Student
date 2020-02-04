/*
난이도 : D2
문제 번호 : 2005
문제 제목 : 파스칼의 삼각형
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testCase, height;
    vector<vector<int>> intVV;
    vector<int> tmpVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> height;

        tmpVec.push_back(1);
        intVV.push_back(tmpVec);
        tmpVec.clear();
        for (int j = 1; j < height; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                int nextNum = 0;
                if (k - 1 >= 0)
                    nextNum += intVV[j - 1][k - 1];
                if (k < intVV[j - 1].size())
                    nextNum += intVV[j - 1][k];
                tmpVec.push_back(nextNum);
            }
            intVV.push_back(tmpVec);
            tmpVec.clear();
        }
        cout << "#" << (i + 1) << endl;
        for (int j = 0; j < intVV.size(); j++)
        {
            for (int k = 0; k < intVV[j].size(); k++)
                cout << intVV[j][k] << " ";
            cout << endl;
        }
        intVV.clear();
    }
    return 0;
}