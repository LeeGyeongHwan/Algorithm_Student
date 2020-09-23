/* 
ACMICPC
Study Group
7th Week
문제 번호 : 14890
문제 제목 : 경사로
풀이 날짜 : 2020-09-23
Solved By Reamer 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> rowVec[100], colVec[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int map[100][100];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (rowVec[i].size() != 0 && rowVec[i].back().first == map[i][j])
                rowVec[i].back().second++;
            else
                rowVec[i].push_back({map[i][j], 1});
            if (colVec[j].size() != 0 && colVec[j].back().first == map[i][j])
                colVec[j].back().second++;
            else
                colVec[j].push_back({map[i][j], 1});
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (rowVec[i].size() == 1)
        {
            cnt++;
            continue;
        }
        bool noRoute = false;
        for (int j = 1; j < rowVec[i].size() && !noRoute; j++)
        {
            pair<int, int> prev = rowVec[i][j - 1];
            pair<int, int> cur = rowVec[i][j];
            if (prev.first + 1 == cur.first)
            {
                if (prev.second < K)
                {
                    noRoute = true;
                    break;
                }
            }
            else if (prev.first == cur.first + 1)
            {
                if (cur.second >= K)
                    rowVec[i][j].second -= K;
                else
                {
                    noRoute = true;
                    break;
                }
            }
            else
            {
                noRoute = true;
                break;
            }
        }
        if (!noRoute)
            cnt++;
    }

    for (int i = 0; i < N; i++)
    {
        if (colVec[i].size() == 1)
        {
            cnt++;
            continue;
        }
        bool noRoute = false;
        for (int j = 1; j < colVec[i].size() && !noRoute; j++)
        {
            pair<int, int> prev = colVec[i][j - 1];
            pair<int, int> cur = colVec[i][j];
            if (prev.first + 1 == cur.first)
            {
                if (prev.second < K)
                {
                    noRoute = true;
                    break;
                }
            }
            else if (prev.first == cur.first + 1)
            {
                if (cur.second >= K)
                    colVec[i][j].second -= K;
                else
                {
                    noRoute = true;
                    break;
                }
            }
            else
            {
                noRoute = true;
                break;
            }
        }
        if (!noRoute)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
