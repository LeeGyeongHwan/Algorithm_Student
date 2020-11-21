/*
ACMICPC
문제 번호 : 10865
문제 제목 : 친구 친구
풀이 날짜 : 2020-11-22
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> intVec[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        intVec[A].push_back(B);
        intVec[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
        cout << intVec[i].size() << "\n";

    return 0;
}