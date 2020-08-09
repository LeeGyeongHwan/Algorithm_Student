/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 1976
문제 제목 : 여행 가자
풀이 날짜 : 2020-08-09
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int disjointSet[201];

int findRoot(int A)
{
    if (disjointSet[A] != A)
        disjointSet[A] = findRoot(disjointSet[A]);
    return disjointSet[A];
}

void unionSet(int A, int B)
{
    int rootA = findRoot(A);
    int rootB = findRoot(B);
    if (rootA == rootB)
        return;
    disjointSet[rootB] = rootA;
}

int main()
{
    int city, plan, tmp;

    cin >> city >> plan;

    for (int i = 1; i <= city; i++)
    {
        disjointSet[i] = i;
    }
    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            cin >> tmp;
            if (tmp == 1)
                unionSet(i, j);
        }
    }

    bool isSameSet = true;
    int representative = -1;

    for (int i = 0; i < plan; i++)
    {
        cin >> tmp;
        int rootValue = findRoot(tmp);
        if (representative == -1)
            representative = rootValue;
        else if (representative != rootValue)
            isSameSet = false;
    }

    if (isSameSet)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}