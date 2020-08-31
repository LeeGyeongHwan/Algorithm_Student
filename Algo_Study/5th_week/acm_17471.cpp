/* 
ACMICPC
Study Group
5th Week
문제 번호 : 17471
문제 제목 : 게리맨더링
풀이 날짜 : 2020-08-29
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N;
int population[11];
vector<int> adjacent[11];
vector<int> teamA, teamB;
int minAbs = INT32_MAX;
bool visited[11];

void DFSA(int num)
{
    visited[num] = true;

    for (int i = 0; i < teamA.size(); i++)
    {
        for (int j = 0; j < adjacent[num].size(); j++)
        {
            if (teamA[i] == adjacent[num][j] && !visited[teamA[i]])
            {
                DFSA(teamA[i]);
                break;
            }
        }
    }
}

void DFSB(int num)
{
    visited[num] = true;

    for (int i = 0; i < teamB.size(); i++)
    {
        for (int j = 0; j < adjacent[num].size(); j++)
        {
            if (teamB[i] == adjacent[num][j] && !visited[teamB[i]])
            {
                DFSB(teamB[i]);
                break;
            }
        }
    }
}

void check()
{
    int popA = 0, popB = 0;
    //teamA
    memset(visited, 0, sizeof(visited));
    DFSA(teamA.front());
    for (int i = 0; i < teamA.size(); i++)
    {
        if (!visited[teamA[i]])
        {
            return;
        }
        popA += population[teamA[i]];
    }

    //teamB
    memset(visited, 0, sizeof(visited));
    DFSB(teamB.front());
    for (int i = 0; i < teamB.size(); i++)
    {
        if (!visited[teamB[i]])
        {
            return;
        }
        popB += population[teamB[i]];
    }
    //갱신
    if (abs(popA - popB) < minAbs)
        minAbs = abs(popA - popB);
}

void separate()
{
    for (int i = 0; i < (1 << N); i++)
    {
        teamA.clear();
        teamB.clear();
        // cout << i << endl;
        for (int j = 0; j < N; j++)
        {
            if ((i & (1 << j)) != 0)
                teamA.push_back(j + 1);
            else
                teamB.push_back(j + 1);
        }

        if (teamA.size() == 0 || teamB.size() == 0)
            continue;
        check();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int area, num;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> population[i];

    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> area;
            adjacent[i].push_back(area);
        }
    }

    separate();
    if (minAbs == INT32_MAX)
        cout << "-1\n";
    else
        cout << minAbs << "\n";

    return 0;
}