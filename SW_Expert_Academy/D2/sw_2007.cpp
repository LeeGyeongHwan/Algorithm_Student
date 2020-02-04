/*
난이도 : D2
문제 번호 : 2007
문제 제목 : 패턴 마디의 길이
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    string str;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int strSum = 0;
        int length = 0;
        cin >> str;
        for (int j = 1; j < str.length(); j++)
        {
            if (!str.substr(0, j).compare(str.substr(j + 1, j)))
            {
                length = j+1;
                break;
            }
        }
        cout << "#" << (i + 1) << " " << length << endl;
    }
    return 0;
}