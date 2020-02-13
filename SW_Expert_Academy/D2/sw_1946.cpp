/*
난이도 : D2
문제 번호 : 1946
문제 제목 : 간단한 압축 풀기
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testCase, number, charNum;
    char alpha;
    vector<vector<char>> charVV;
    vector<char> tmpVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> number;
        for (int j = 0; j < number; j++)
        {
            cin >> alpha >> charNum;

            for (int k = 0; k < charNum; k++)
            {
                if (tmpVec.empty() || tmpVec.size() < 10)
                {
                    tmpVec.push_back(alpha);
                }
                else
                {
                    charVV.push_back(tmpVec);
                    tmpVec.clear();
                    tmpVec.push_back(alpha);
                }
            }
        }
        if (!tmpVec.empty())
            charVV.push_back(tmpVec);

        cout << "#" << (i + 1) << endl;
        for (int j = 0; j < charVV.size(); j++)
        {
            for (int k = 0; k < charVV[j].size(); k++)
                cout << charVV[j].at(k);
            cout << endl;
        }
        charVV.clear();
        tmpVec.clear();
    }
    return 0;
}