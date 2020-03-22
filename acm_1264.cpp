/*
ACMICPC
문제 번호 : 1264
문제 제목 : 모음의 개수
풀이 날짜 : 2020-03-22
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    string tmp;
    while (1)
    {
        int count = 0;
        getline(cin, tmp);
        if (!tmp.compare("#"))
            break;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u' ||
                tmp[i] == 'A' || tmp[i] == 'E' || tmp[i] == 'I' || tmp[i] == 'O' || tmp[i] == 'U')
                count++;
        }
        cout << count << endl;
    }
}