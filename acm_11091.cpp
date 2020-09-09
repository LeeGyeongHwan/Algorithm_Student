/*
ACMICPC
문제 번호 : 11091
문제 제목 : 알파벳 전부 쓰기
풀이 날짜 : 2020-09-09
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int alphabet[200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;
    getline(cin, str);
    N = stoi(str);

    for (int i = 0; i < N; i++)
    {
        memset(alphabet, 0, sizeof(alphabet));
        getline(cin, str);

        for (int j = 0; j < str.length(); j++)
        {
            int charToNum = (int)tolower(str[j]);
            alphabet[charToNum]++;
        }
        string missing = "";
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (alphabet[i] == 0)
                missing += (char)i;
        }

        if (missing == "")
            cout << "pangram\n";
        else
            cout << "missing " << missing << "\n";
    }

    return 0;
}