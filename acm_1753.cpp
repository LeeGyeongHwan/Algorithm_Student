/*
ACMICPC
문제 번호 : 1753
문제 제목 : 최단경로
풀이 날짜 : 2020-08-25
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> pairVec[20001];
int dijk[20001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    int start, from, to, dist;
    vector<pair<int, int>> tmpVec;
    cin >> V >> E;
    cin >> start;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> dist;
        pairVec[from].push_back({dist, to});
    }

    for (int i = 1; i <= V; i++)
    {
        dijk[i] = INT32_MAX;
    }

    dijk[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int dest = pq.top().second;
        pq.pop();

        tmpVec = pairVec[dest];
        int size = tmpVec.size();
        for (int i = 0; i < size; i++)
        {
            int newCost = tmpVec[i].first;  //cost
            int newDest = tmpVec[i].second; //dest
            if (dijk[newDest] > cost + newCost)
            {
                dijk[newDest] = cost + newCost;
                pq.push({cost + newCost, newDest});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dijk[i] == INT32_MAX)
            cout << "INF\n";
        else
            cout << dijk[i] << "\n";
    }

    return 0;
}