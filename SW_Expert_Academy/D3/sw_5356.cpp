/*
난이도 : D3
문제 번호 : 5356
문제 제목 : 의석이의 세로로 말해요
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

    int testCase;
    string str;
    vector<string> strVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxLength = 0;
        string answer = "";
        for (int j = 0; j < 5; j++)
        {
            cin >> str;
            strVec.push_back(str);
            if (str.length() > maxLength)
                maxLength = str.length();
        }

        for (int j = 0; j < maxLength; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (strVec[k].length() > j)
                    answer += strVec[k].at(j);
            }
        }

        cout << "#" << (i + 1) << " " << answer << "\n";
        strVec.clear();
    }

    return 0;
}