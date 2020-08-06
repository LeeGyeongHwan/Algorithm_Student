/*
ACMICPC
문제 번호 : 1197
문제 제목 : 최소 스패닝 트리
풀이 날짜 : 2020-08-06
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int vertex[10001];

bool compare(tuple<int, int, int> A, tuple<int, int, int> B)
{
    int ax, ay, az;
    int bx, by, bz;
    tie(ax, ay, az) = A;
    tie(bx, by, bz) = B;
    return az < bz;
}
int findSet(int A)
{
    if (A != vertex[A])
        vertex[A] = findSet(vertex[A]);
    return vertex[A];
}

bool unionSet(int A, int B)
{
    int rootA = findSet(A);
    int rootB = findSet(B);
    if (rootA == rootB)
        return false;
    vertex[rootB] = rootA;
    return true;
}

int main()
{
    int V, E;

    vector<tuple<int, int, int>> tupleV;
    cin >> V >> E;

    int from, to, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        tupleV.push_back(make_tuple(from, to, weight));
    }
    for (int i = 1; i <= V; i++)
    {
        vertex[i] = i;
    }
    sort(tupleV.begin(), tupleV.end(), compare);

    int cnt = 0;
    int sumWeight = 0;

    for (int i = 0; i < tupleV.size(); i++)
    {
        tie(from, to, weight) = tupleV[i];
        if (unionSet(from, to))
        {
            sumWeight += weight;
            if (++cnt == V - 1)
                break;
        }
    }

    cout << sumWeight << endl;

    return 0;
}