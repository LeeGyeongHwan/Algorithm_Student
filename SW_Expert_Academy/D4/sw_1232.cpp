/*
난이도 : D4
문제 번호 : 1232    
문제 제목 : 사칙연산
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

double arithmeticFunc(char *word, int *numTable, int start)
{
    if (word[start] == '+')
        return arithmeticFunc(word, numTable, numTable[start]) + arithmeticFunc(word, numTable, numTable[start] + 1);
    else if (word[start] == '-')
        return arithmeticFunc(word, numTable, numTable[start]) - arithmeticFunc(word, numTable, numTable[start] + 1);
    else if (word[start] == '*')
        return arithmeticFunc(word, numTable, numTable[start]) * arithmeticFunc(word, numTable, numTable[start] + 1);
    else if (word[start] == '/')
        return arithmeticFunc(word, numTable, numTable[start]) / arithmeticFunc(word, numTable, numTable[start] + 1);
    else
        return numTable[start];
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    string str;
    vector<string> strVec;
    char word[1001] = {0};
    int numTable[1001] = {0};

    for (int i = 0; i < 10; i++)
    {
        int start = 1;
        double total = 0;
        getline(cin, str);
        int num = stoi(str);
        for (int j = 0; j < num; j++)
        {
            getline(cin, str);
            strVec = split(str, ' ');
            if (strVec[1] == "-" || strVec[1] == "+" || strVec[1] == "*" || strVec[1] == "/")
            {
                word[stoi(strVec.front())] = strVec[1].front();
                numTable[stoi(strVec.front())] = stoi(strVec[2]);
            }
            else
            {
                word[stoi(strVec.front())] = 'N';
                numTable[stoi(strVec.front())] = stoi(strVec[1]);
            }
        }

        int startNum = 1;
        total = arithmeticFunc(word, numTable, startNum);

        cout << "#" << (i + 1) << " " << total << endl;

        memset(word, 0, sizeof(word));
        memset(numTable, 0, sizeof(numTable));
        strVec.clear();
    }

    return 0;
}
