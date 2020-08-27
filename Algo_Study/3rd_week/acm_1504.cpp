/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 1504
문제 제목 : 특정한 최단 경로
풀이 날짜 : 2020-08-27
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> pairVec[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dijk[801];
bool isVisit[801];
int N, A, B;
bool isAnswer = true;

void dijkstra(int from, int to)
{
    int minDist = 1000000000;

    for (int i = 1; i <= N; i++)
        dijk[i] = 1000000000;

    dijk[from] = 0;
    isVisit[from] = true;
    pq.push({0, from});
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int dest = pq.top().second;
        pq.pop();
        for (int i = 0; i < pairVec[dest].size(); i++)
        {
            int newCost = pairVec[dest][i].first;
            int newDest = pairVec[dest][i].second;

            if (dijk[newDest] > cost + newCost)
            {
                dijk[newDest] = cost + newCost;
                pq.push({cost + newCost, newDest});
            }
        }
    }
    if (dijk[to] == 1000000000)
        isAnswer = false;
    while (!pq.empty())
        pq.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int E;
    int from, to, cost;

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        pairVec[from].push_back({cost, to});
        pairVec[to].push_back({cost, from});
    }
    cin >> A >> B;

    //1->A->B->N
    int distA = 0;
    dijkstra(1, A);
    distA += dijk[A];
    dijkstra(A, B);
    distA += dijk[B];
    dijkstra(B, N);
    distA += dijk[N];
    if (!isAnswer)
        distA = 1000000000;

    isAnswer = true;

    //1->B->A->N
    int distB = 0;
    dijkstra(1, B);
    distB += dijk[B];
    dijkstra(B, A);
    distB += dijk[A];
    dijkstra(A, N);
    distB += dijk[N];
    if (!isAnswer)
        distB = 1000000000;
    int minDist = distA > distB ? distB : distA;

    if (minDist == 1000000000)
        cout << "-1\n";
    else
        cout << minDist << "\n";
    return 0;
}