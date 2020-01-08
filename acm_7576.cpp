#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<vector<int>> boxVec;
    vector<int> tmpVec;
    queue<pair<int, int>> pairQ;
    bool visited[1001][1001] = {false};
    int M, N, tmp;

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                pairQ.push(make_pair(i, j));
                visited[i][j] = true;
            }
            tmpVec.push_back(tmp);
        }
        boxVec.push_back(tmpVec);
        tmpVec.clear();
    }

    while (!pairQ.empty())
    {
        int pointX = pairQ.front().first;
        int pointY = pairQ.front().second;
        pairQ.pop();

        if (pointX - 1 >= 0)
        {
            if (boxVec[pointX - 1][pointY] >= 0 && !visited[pointX - 1][pointY])
            {
                visited[pointX - 1][pointY] = true;
                pairQ.push(make_pair(pointX - 1, pointY));
                boxVec[pointX - 1][pointY] = boxVec[pointX][pointY] + 1;
            }
        }

        if (pointY - 1 >= 0)
        {
            if (boxVec[pointX][pointY - 1] >= 0 && !visited[pointX][pointY - 1])
            {
                visited[pointX][pointY - 1] = true;
                pairQ.push(make_pair(pointX, pointY - 1));
                boxVec[pointX][pointY - 1] = boxVec[pointX][pointY] + 1;
            }
        }

        if (pointX + 1 < N)
        {
            if (boxVec[pointX + 1][pointY] >= 0 && !visited[pointX + 1][pointY])
            {
                visited[pointX + 1][pointY] = true;
                pairQ.push(make_pair(pointX + 1, pointY));
                boxVec[pointX + 1][pointY] = boxVec[pointX][pointY] + 1;
            }
        }

        if (pointY + 1 < M)
        {
            if (boxVec[pointX][pointY + 1] >= 0 && !visited[pointX][pointY + 1])
            {
                visited[pointX][pointY + 1] = true;
                pairQ.push(make_pair(pointX, pointY + 1));
                boxVec[pointX][pointY + 1] = boxVec[pointX][pointY] + 1;
            }
        }
    }

    int maxDay = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (boxVec[i][j] > maxDay)
            {
                maxDay = boxVec[i][j];
            }
            if (boxVec[i][j] == 0)
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << maxDay - 1 << endl;

    return 0;
}