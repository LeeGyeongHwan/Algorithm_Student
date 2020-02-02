/*
난이도 : D3
문제 번호 : 8741
문제 제목 : 두문자어
풀이 날짜 : 2020-02-02
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        string tmp;
        string answer;
        for (int j = 0; j < 3; j++)
        {
            cin >> tmp;
            answer += (char)(tmp[0] - 32);
        }

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}