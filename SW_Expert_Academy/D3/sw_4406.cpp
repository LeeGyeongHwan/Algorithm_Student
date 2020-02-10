/*
난이도 : D3
문제 번호 : 4406
문제 제목 : 모음이 보이지 않는 사람
풀이 날짜 : 2020-02-10
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
        string answer = "";
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] != 'a' && str[j] != 'e' && str[j] != 'i' && str[j] != 'o' && str[j] != 'u')
            {
                answer += str[j];
            }
        }

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}