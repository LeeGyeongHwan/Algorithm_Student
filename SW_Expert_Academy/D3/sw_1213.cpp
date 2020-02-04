/*
난이도 : D3
문제 번호 : 1213
문제 제목 : String
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;
    string searchStr, compareStr;
    vector<char> charVec;

    for (int i = 0; i < 10; i++)
    {
        int searchNum = 0;
        cin >> testCase;
        cin >> searchStr >> compareStr;
        int length = searchStr.length();

        for (int j = length - 1; j >= 0; j--)
        {
            charVec.push_back(searchStr[j]);
        }
        
        for (int j = length - 1; j < compareStr.length(); j += length)
        {
            if (charVec[0] == compareStr[j])
            {
                bool isSame = true;
                for (int k = 1; k < length; k++)
                {
                    if (charVec[k] != compareStr[j - k])
                    {
                        isSame = false;
                        break;
                    }
                }
                if (isSame)
                {
                    searchNum++;
                }
            }
            else
            {
                for (int k = 1; k < length; k++)
                {
                    if (charVec[k] == compareStr[j])
                    {
                        j += (k - length);
                        break;
                    }
                }
            }
        }

        cout << "#" << testCase << " " << searchNum << endl;
        charVec.clear();
    }
    return 0;
}