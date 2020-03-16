/*
ACMICPC
문제 번호 : 11656
문제 제목 : 접미사 배열
풀이 날짜 : 2020-03-16
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str, tmp;
    vector<string> strVec;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        tmp = str.substr(i, str.length());
        strVec.push_back(tmp);
    }
    sort(strVec.begin(), strVec.end());
    for (int i = 0; i < strVec.size(); i++)
    {
        cout << strVec[i] << endl;
    }
    return 0;
}