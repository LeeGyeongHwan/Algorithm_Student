/* 
ACMICPC 
문제 번호 : 11536
문제 제목 : 줄 세우기
풀이 날짜 : 2020-05-29
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool decrease(string A, string B)
{
    if (A > B)
        return true;
    else
        return false;
}

bool increase(string A, string B)
{
    if (A < B)
        return true;
    else
        return false;
}

int main()
{
    int N;
    string str;
    vector<string> strVec, iVec, dVec;
    bool isIncrease = true;
    bool isDecrease = true;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        strVec.push_back(str);
    }

    iVec.assign(strVec.begin(), strVec.end());
    dVec.assign(strVec.begin(), strVec.end());

    sort(iVec.begin(), iVec.end(), increase);
    sort(dVec.begin(), dVec.end(), decrease);

    for (int i = 0; i < strVec.size(); i++)
    {
        if (strVec[i] != iVec[i])
        {
            isIncrease = false;
        }
        if (strVec[i] != dVec[i])
        {
            isDecrease = false;
        }
    }

    if (isIncrease)
        cout << "INCREASING" << endl;
    else if (isDecrease)
        cout << "DECREASING" << endl;
    else
        cout << "NEITHER" << endl;

    return 0;
}