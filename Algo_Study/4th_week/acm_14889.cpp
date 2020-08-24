/* 
ACMICPC
Study Group
4th Week
문제 번호 : 14889
문제 제목 : 스타트와 링크
풀이 날짜 : 2020-08-24
Solved By Reamer 
*/

#include <iostream>
#include <vector>
using namespace std;

int ability[20][20];
int team[20];

int N;
int minNum = INT32_MAX;

void makeTeam()
{
    int teamA = 0;
    int teamB = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (team[i] == 1 && team[j] == 1)
                teamA += ability[i][j];
            else if (team[i] == 0 && team[j] == 0)
                teamB += ability[i][j];
        }
    }
    int diff = abs(teamB - teamA);
    if (minNum > diff)
        minNum = diff;
}

void combination(int cnt, int start)
{
    if (cnt == N / 2 - 1)
    {
        makeTeam();
        return;
    }
    for (int i = start; i < N; i++)
    {
        team[i] = 1;
        combination(cnt + 1, i + 1);
        team[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ability[i][j];
        }
    }

    team[0] = 1;
    combination(0, 1);
    cout << minNum << "\n";

    return 0;
}