/*
난이도 : D4
문제 번호 : 1231
문제 제목 : 중위순회
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
    char word[101] = {0};
    bool isVisited[101] = {0};

    for (int i = 0; i < 10; i++)
    {
        int start = 1;
        getline(cin, str);
        int num = stoi(str);
        for (int j = 0; j < num; j++)
        {
            getline(cin, str);
            strVec = split(str, ' ');
            word[stoi(strVec.front())] = strVec[1].front();
        }
        while (start <= num)
            start *= 2;
        start /= 2;
        isVisited[start] = true;
        cout << "#" << (i + 1) << " ";
        for (int j = 0; j < num; j++)
        {
            cout << word[start];
            isVisited[start] = true;
            if (word[start + start] != 0 && !isVisited[start + start])
            {
                while (word[start + start] != 0 && !isVisited[start + start])
                    start += start;
            }
            else if (word[start + start + 1] != 0 && !isVisited[start + start + 1])
            {
                start += start + 1;
                while (word[start + start] != 0 && !isVisited[start + start])
                    start += start;
            }
            else if (word[start / 2] != 0 && !isVisited[start / 2])
                start /= 2;
            else if (isVisited[start / 2])
            {
                while (isVisited[start])
                    start /= 2;
            }
        }
        cout << endl;

        memset(word, 0, sizeof(word));
        memset(isVisited, 0, sizeof(isVisited));
        strVec.clear();
    }

    return 0;
}
