/*
난이도 : D3
문제 번호 : 8104
문제 제목 : 조 만들기
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, people, group;
    int team[20] = {0};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> people >> group;

        for (int j = 0; j < people; j++)
        {
            for (int k = 0; k < group; k++)
            {
                if (j % 2 == 0)
                    team[k] += group * j + (k + 1);
                else
                    team[group - 1 - k] += group * j + (k + 1);
            }
        }

        cout << "#" << (i + 1);
        for (int j = 0; j < group; j++)
            cout << " " << team[j];
        cout << endl;
        memset(team, 0, sizeof(team));
    }
    return 0;
}