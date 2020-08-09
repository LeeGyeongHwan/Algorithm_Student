/* 
ACMICPC 
문제 번호 : 1717
문제 제목 : 집합의 표현
풀이 날짜 : 2020-08-09
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int disSet[1000001] = {0};

int findRoot(int a)
{
    if (disSet[a] != a)
        disSet[a] = findRoot(disSet[a]);
    return disSet[a];
}

void unionSet(int a, int b)
{
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA == rootB)
        return;

    disSet[rootB] = rootA;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int op, a, b;
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        disSet[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> op >> a >> b;

        if (op == 0)
        {
            unionSet(a, b);
        }
        else
        {
            int A = findRoot(a);
            int B = findRoot(b);
            if (A == B)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}