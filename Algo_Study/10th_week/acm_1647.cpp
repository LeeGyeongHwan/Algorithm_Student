/* 
ACMICPC
Study Group
10th Week
문제 번호 : 1647
문제 제목 : 도시 분할 계획
풀이 날짜 : 2020-10-13
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<int, int, int> A, tuple<int, int, int> B)
{
    int ax, ay, az, bx, by, bz;
    tie(ax, ay, az) = A;
    tie(bx, by, bz) = B;
    return az < bz;
}

int arr[100001];

int findRoot(int A)
{
    if (arr[A] != A)
        arr[A] = findRoot(arr[A]);
    return arr[A];
}

bool unionSet(int A, int B)
{
    int rootA = findRoot(A);
    int rootB = findRoot(B);
    if (rootA == rootB)
        return false;
    arr[rootB] = rootA;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    int A, B, C;
    vector<tuple<int, int, int>> tVec;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        tVec.push_back({A, B, C});
    }

    sort(tVec.begin(), tVec.end(), compare);

    for (int i = 1; i <= N; i++)
        arr[i] = i;

    int maxRoute = 0;
    int distSum = 0;
    for (int i = 0; i < M; i++)
    {
        tie(A, B, C) = tVec[i];
        if (unionSet(A, B))
        {
            distSum += C;
            maxRoute = C;
        }
    }
    cout << distSum - maxRoute << "\n";

    return 0;
}