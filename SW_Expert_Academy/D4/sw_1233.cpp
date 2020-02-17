/*
난이도 : D4
문제 번호 : 1233
문제 제목 : 사칙연산 유효성 검사
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> returnVec;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, delimiter))
    {
        returnVec.push_back(tmp);
    }
    return returnVec;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    string str;
    vector<string> strVec;
    char word[201] = {0};
    bool isVisited[201] = {0};

    for (int i = 0; i < 10; i++)
    {
        bool isValid = true;
        getline(cin, str);
        int num = stoi(str);
        for (int j = 0; j < num; j++)
        {
            getline(cin, str);
            strVec = split(str, ' ');
            word[stoi(strVec.front())] = strVec[1].front();
        }

        for (int j = 1; j <= num; j++)
        {
            if (word[j + j] != 0 && word[j + j + 1] != 0)
            {
                if (word[j] >= 48 && word[j] <= 57)
                {
                    isValid = false;
                    break;
                }
            }
            else
            {
                if (!word[j] >= 48 && word[j] <= 57)
                {
                    isValid = false;
                    break;
                }
            }
        }

        cout << "#" << (i + 1) << " " << isValid << endl;

        memset(word, 0, sizeof(word));
        memset(isVisited, 0, sizeof(isVisited));
        strVec.clear();
    }

    return 0;
}
