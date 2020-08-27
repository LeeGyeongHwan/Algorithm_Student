/* 
ACMICPC
Study Group
5th Week
문제 번호 : 15927
문제 제목 : 회문은 회문아니야!!
풀이 날짜 : 2020-08-27
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

bool isSame = true;

bool checkPalin(string tmp)
{
    int size = tmp.length();

    for (int i = 0; i <= size / 2; i++)
    {
        if (tmp[i] != tmp[size - i - 1])
            return false;
        if (tmp[0] != tmp[i])
            isSame = false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;

    if (checkPalin(str))
    {
        if (isSame)
            cout << "-1\n";
        else
            cout << str.length() - 1 << "\n";
    }
    else
        cout << str.size() << "\n";
    return 0;
}