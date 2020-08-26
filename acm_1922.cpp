/*
ACMICPC
문제 번호 : 1922
문제 제목 : 네트워크 연결
풀이 날짜 : 2020-08-26
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int val[1001];

bool compare(tuple<int, int, int> A, tuple<int, int, int> B)
{
    int ax, ay, ac;
    int bx, by, bc;
    tie(ax, ay, ac) = A;
    tie(bx, by, bc) = B;

    return ac < bc;
}
int findSet(int a)
{
    if (a != val[a])
        val[a] = findSet(val[a]);
    return val[a];
}
bool unionSet(int a, int b)
{
    int rootA = findSet(a);
    int rootB = findSet(b);
    if (rootA == rootB)
        return false;
    val[rootB] = rootA;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<tuple<int, int, int>> tupleV;
    int N, M;
    int from, to, cost;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        tupleV.push_back({from, to, cost});
    }
    sort(tupleV.begin(), tupleV.end(), compare);

    for (int i = 1; i <= N; i++)
        val[i] = i;

    int totalCost = 0;
    int cnt = 0;
    for (int i = 0; i < tupleV.size(); i++)
    {
        tie(from, to, cost) = tupleV[i];
        if (from == to)
            continue;
        if (unionSet(from, to))
        {
            totalCost += cost;
            cnt++;
        }

        if (cnt == N - 1)
            break;
    }
    cout << totalCost << "\n";
    return 0;
}