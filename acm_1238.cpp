/*
ACMICPC
문제 번호 : 1238
문제 제목 : 파티
풀이 날짜 : 2020-08-26
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> pairVec[1001];
int dijk[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int N, M, X;
    int from, to, cost;
    int maxTime = 0;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        pairVec[from].push_back({cost, to});
    }

    for (int i = 1; i <= N; i++)
    {
        int roundTrip = 0;

        for (int j = 1; j <= N; j++)
            dijk[j] = INT32_MAX;

        int start = i;
        dijk[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int destination = pq.top().second;
            pq.pop();

            for (int j = 0; j < pairVec[destination].size(); j++)
            {
                int newCost = cost + pairVec[destination][j].first;
                int newDest = pairVec[destination][j].second;
                if (dijk[newDest] > newCost)
                {
                    dijk[newDest] = newCost;
                    pq.push({newCost, newDest});
                }
            }
        }
        roundTrip += dijk[X];

        //X에서 돌아옴
        for (int j = 1; j <= N; j++)
            dijk[j] = INT32_MAX;

        start = X;
        dijk[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int destination = pq.top().second;
            pq.pop();

            for (int j = 0; j < pairVec[destination].size(); j++)
            {
                int newCost = cost + pairVec[destination][j].first;
                int newDest = pairVec[destination][j].second;
                if (dijk[newDest] > newCost)
                {
                    dijk[newDest] = newCost;
                    pq.push({newCost, newDest});
                }
            }
        }
        roundTrip += dijk[i];

        if (roundTrip > maxTime)
            maxTime = roundTrip;
    }
    cout << maxTime << "\n";
    return 0;
}