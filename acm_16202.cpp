/* 
ACMICPC 
문제 번호 : 16202
문제 제목 : MST 게임
풀이 날짜 : 2020-08-16
Solved By Reamer 
*/

#include <iostream>
#include <vector>
using namespace std;

int disSet[1001];

int findSet(int A)
{
    if (disSet[A] != A)
        disSet[A] = findSet(disSet[A]);
    return disSet[A];
}

bool unionSet(int A, int B)
{
    int rootA = findSet(A);
    int rootB = findSet(B);

    if (rootA == rootB)
        return false;
    disSet[rootB] = rootA;
    return true;
}

void makeSet(int idx)
{
    for (int i = 1; i <= idx; i++)
        disSet[i] = i;
}

int main()
{
    int N, M, K;

    int x, y;
    vector<pair<int, int>> pairVec;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        pairVec.push_back({x, y});
    }
    bool canMake = true;
    for (int i = 0; i < K; i++)
    {
        if (!canMake)
        {
            cout << "0 ";
            continue;
        }
        int score = 0;
        makeSet(N);
        int cnt = 0;
        for (int j = i; j < pairVec.size(); j++)
        {
            if (!unionSet(pairVec[j].first, pairVec[j].second))
                continue;
            score += j + 1;
            if (++cnt == N - 1)
                break;
        }
        if (cnt != N - 1)
            canMake = false;
        if (!canMake)
            cout << "0 ";
        else
            cout << score << " ";
    }
    return 0;
}