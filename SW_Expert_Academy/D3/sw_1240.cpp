/*
난이도 : D3
문제 번호 : 1240
문제 제목 : 단순 2진 암호코드
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, M;
    string str;
    vector<string> strVec;
    vector<int> intVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        string codeStr;
        int encryptCode = 0, answer = 0;
        int lastIndex = 0;
        cin >> N >> M;

        for (int j = 0; j < N; j++)
        {
            cin >> str;
            for (int k = 0; k < M; k++)
            {
                if (str[k] == '1')
                {
                    lastIndex = k;
                    codeStr = str;
                }
            }
        }
        codeStr = codeStr.substr(lastIndex - 56 + 1, 56);
        do
        {
            string tmp = codeStr.substr(0, 7);
            if (tmp == "0001101")
                intVec.push_back(0);
            else if (tmp == "0011001")
                intVec.push_back(1);
            else if (tmp == "0010011")
                intVec.push_back(2);
            else if (tmp == "0111101")
                intVec.push_back(3);
            else if (tmp == "0100011")
                intVec.push_back(4);
            else if (tmp == "0110001")
                intVec.push_back(5);
            else if (tmp == "0101111")
                intVec.push_back(6);
            else if (tmp == "0111011")
                intVec.push_back(7);
            else if (tmp == "0110111")
                intVec.push_back(8);
            else if (tmp == "0001011")
                intVec.push_back(9);
            codeStr = codeStr.substr(7);
        } while (codeStr.size() != 0);

        for (int j = 0; j < intVec.size(); j++)
        {
            if (j % 2 == 0)
                encryptCode += intVec[j] * 3;
            else
                encryptCode += intVec[j];
            answer += intVec[j];
        }

        if (encryptCode % 10 == 0)
            cout << "#" << (i + 1) << " " << answer << endl;
        else
            cout << "#" << (i + 1) << " " << 0 << endl;
        strVec.clear();
        intVec.clear();
    }

    return 0;
}