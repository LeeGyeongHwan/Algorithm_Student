/*
ACMICPC
문제 번호 : 1916
문제 제목 : 최소비용 구하기
풀이 날짜 : 2020-08-25
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> pairVec[1001];
int dijk[1001];
bool isSelected[1001];

int main()
{
    int N, M;
    int from, to, cost;
    int start, dest;
    vector<pair<int, int>> tmpVec;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        pairVec[from].push_back({to, cost});
    }
    cin >> start >> dest;
    for (int i = 1; i <= N; i++)
    {
        dijk[i] = INT32_MAX;
    }

    dijk[start] = 0;
    int minDist = INT32_MAX;
    int idx = -1;

    while (true)
    {
        tmpVec = pairVec[start];
        isSelected[start] = true;
        int length = tmpVec.size();
        for (int i = 0; i < length; i++)
        {
            int dest = tmpVec[i].first;
            dijk[dest] = min(dijk[dest], dijk[start] + tmpVec[i].second);
        }

        int minDist = INT32_MAX;
        int idx = -1;
        for (int i = 1; i <= N; i++)
        {
            if (!isSelected[i] && minDist > dijk[i])
            {
                minDist = dijk[i];
                idx = i;
            }
        }

        if (idx == -1)
            break;
        start = idx;
    }

    cout << dijk[dest] << "\n";

    return 0;
}