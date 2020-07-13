/*
난이도 : D3
문제 번호 : 1216
문제 제목 : 회문2
풀이 날짜 : 2020-07-13
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    string str;
    vector<string> strVec;

    for (int i = 0; i < 10; i++)
    {
        int maxLength = 1;

        cin >> testCase;

        for (int j = 0; j < 100; j++)
        {
            cin >> str;
            strVec.push_back(str);
        }

        for (int j = 0; j < 100; j++)
        {
            for (int k = 100; k > maxLength; k--)
            {
                for (int l = 0; l < 101 - k; l++)
                {
                    bool isPalin = true;
                    for (int m = 0; m <= k / 2; m++)
                    {
                        if (strVec[j][l + m] != strVec[j][l + k - m - 1])
                        {
                            isPalin = false;
                            break;
                        }
                    }
                    if (isPalin)
                    {
                        if (maxLength < k)
                        {
                            maxLength = k;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 100; j++)
        {
            for (int k = 100; k > maxLength; k--)
            {
                for (int l = 0; l < 101 - k; l++)
                {
                    bool isPalin = true;
                    for (int m = 0; m <= k / 2; m++)
                    {
                        if (strVec[l + m][j] != strVec[l + k - m - 1][j])
                        {
                            isPalin = false;
                            break;
                        }
                    }
                    if (isPalin)
                    {
                        if (maxLength < k)
                        {
                            maxLength = k;
                        }
                    }
                }
            }
        }

        cout << "#" << testCase << " " << maxLength << endl;
        strVec.clear();
    }
    return 0;
}