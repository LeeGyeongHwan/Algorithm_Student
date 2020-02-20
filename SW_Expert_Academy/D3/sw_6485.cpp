/*
난이도 : D3
문제 번호 : 6485
문제 제목 : 삼성시의 버스 노선
풀이 날짜 : 2020-02-20
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, A, B, P, tmp;
    vector<pair<int, int>> busVec, stopVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> A >> B;
            busVec.push_back(make_pair(A, B));
        }
        cin >> P;
        for (int j = 0; j < P; j++)
        {
            cin >> tmp;
            stopVec.push_back(make_pair(tmp, 0));
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < P; k++)
            {
                if (busVec[j].first <= stopVec[k].first && busVec[j].second >= stopVec[k].first)
                    stopVec[k].second++;
            }
        }
        cout << "#" << (i + 1);
        for (int j = 0; j < P; j++)
            cout << " " << stopVec[j].second;
        cout << "\n";
        busVec.clear();
        stopVec.clear();
    }

    return 0;
}