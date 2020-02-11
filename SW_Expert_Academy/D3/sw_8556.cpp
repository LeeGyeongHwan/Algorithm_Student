/*
난이도 : D3
문제 번호 : 8556
문제 제목 : 북북서
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <math.h>
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
        int degree, quot;
        cin >> str;

        while (str != "")
        {
            if (str[str.length() - 1] == 't') //west 4
            {
                strVec.push_back("west");
                str = str.substr(0, str.length() - 4);
            }
            else //north 5
            {
                strVec.push_back("north");
                str = str.substr(0, str.length() - 5);
            }
        }

        if (!strVec.front().compare("west"))
            degree = 90 * pow(2, strVec.size() - 1);
        else
            degree = 0;

        for (int j = 1; j < strVec.size(); j++)
        {
            if (!strVec[j].compare("west"))
                degree += 90 * pow(2, strVec.size() - 1 - j);
            else
                degree -= 90 * pow(2, strVec.size() - 1 - j);
        }

        quot = pow(2, strVec.size() - 1);
        while (quot != 1)
        {
            if (degree % 2 != 0)
                break;
            degree /= 2;
            quot /= 2;
        }

        if (quot == 1)
            cout << "#" << (i + 1) << " " << degree << endl;
        else
            cout << "#" << (i + 1) << " " << degree << "/" << quot << endl;

        strVec.clear();
    }
    return 0;
}