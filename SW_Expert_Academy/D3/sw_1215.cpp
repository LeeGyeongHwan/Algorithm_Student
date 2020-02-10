/*
난이도 : D3
문제 번호 : 1215
문제 제목 : 회문1
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    string str;
    vector<string> strVec;

    for (int i = 0; i < 10; i++)
    {
        int palin = 0;
        cin >> length;
        for (int j = 0; j < 8; j++)
        {
            cin >> str;
            strVec.push_back(str);
        }

        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                bool isRowPalin = true;
                bool isColPalin = true;
                for (int l = 0; l < length / 2; l++)
                {
                    if (k <= 8 - length && strVec[j].at(k + l) != strVec[j].at(k + length - l - 1))
                        isRowPalin = false;
                    if (j <= 8 - length && strVec[j + l].at(k) != strVec[j + length - l - 1].at(k))
                        isColPalin = false;
                }
                if (k <= 8 - length &&isRowPalin)
                    palin++;
                if (j <= 8 - length &&isColPalin)
                    palin++;
            }
        }

        cout << "#" << (i + 1) << " " << palin << "\n";
        strVec.clear();
    }
    return 0;
}