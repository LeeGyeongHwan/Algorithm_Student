/*
ACMICPC
문제 번호 : 7795
문제 제목 : 먹을 것인가 먹힐 것인가
풀이 날짜 : 2020-09-08
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vecA, vecB;

    int T, N, M, tmp;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int sum = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            vecA.push_back(tmp);
        }
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            vecB.push_back(tmp);
        }
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end());

        int startA = 0, startB = 0;
        while (true)
        {
            if(startB==vecB.size() || startA == vecA.size())
                break;
            if(vecA[startA]<=vecB[startB])
                startA++;
            else
            {
                sum+=vecA.size()-startA;
                startB++;
            }
        }

        cout << sum << "\n";
        vecA.clear();
        vecB.clear();
    }

    return 0;
}