/*
ACMICPC
문제 번호 : 5698
문제 제목 : Tautogram 
풀이 날짜 : 2020-08-19
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str, tmp;

    while (true)
    {
        getline(cin, str);
        char tmpChar = str[0];
        if (!str.compare("*"))
            break;
        stringstream ss;
        ss.str(str);
        bool isAnswer = true;

        while (ss >> tmp)
        {
            if (!(abs(tmp[0] - tmpChar) == 0 || abs(tmp[0] - tmpChar) == 32))
            {
                isAnswer = false;
                break;
            }
        }
        if (isAnswer)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}