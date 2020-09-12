/*
ACMICPC
문제 번호 : 1516
문제 제목 : 게임 개발
풀이 날짜 : 2020-09-12
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int buildTime[501];
int totalTime[501];
vector<int> intVec[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, time, building;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> N;

    for (int i = 1; i <= N; i++)
        totalTime[i] = INT32_MAX;

    int maxSize = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> time;
        buildTime[i] = time;
        while (true)
        {
            cin >> building;
            if (building == -1)
                break;
            intVec[i].push_back(building);
        }
        if (maxSize < intVec[i].size())
            maxSize = intVec[i].size();
        pq.push({intVec[i].size(), i});
    }

    while (!pq.empty())
    {
        int size, idx;
        tie(size, idx) = pq.top();
        pq.pop();

        bool canBuild = true;
        int maxTime = 0;

        for (int i = 0; i < intVec[idx].size(); i++)
        {
            int tmpTime = totalTime[intVec[idx][i]];
            if (tmpTime == INT32_MAX)
            {
                canBuild = false;
                break;
            }
            if (maxTime < tmpTime)
                maxTime = tmpTime;
        }

        if (canBuild)
            totalTime[idx] = maxTime + buildTime[idx];
        else
            pq.push({++maxSize, idx});
    }

    for (int i = 1; i <= N; i++)
        cout << totalTime[i] << "\n";

    return 0;
}