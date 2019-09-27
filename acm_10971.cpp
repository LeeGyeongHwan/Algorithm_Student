#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, tmp;
    cin >> N;
    vector<int> tmpVec, numVec;
    vector<vector<int>> intVec;
    int minCost = 10000000;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            tmpVec.push_back(tmp);
        }
        intVec.push_back(tmpVec);
        numVec.push_back(i);
        tmpVec.clear();
    }

    do
    {
        bool noWay = false;
        int cost = 0;
        for (int i = 0; i < N - 1; i++)
        {
            int start = numVec[i];
            int destination = numVec[i + 1];
            if (intVec[start][destination] == 0)
            {
                noWay = true;
                break;
            }
            cost += intVec[start][destination];
        }
        if (intVec[numVec[N - 1]][numVec[0]] != 0)
        {
            cost += intVec[numVec[N - 1]][numVec[0]];
        }
        else
        {
            noWay = true;
        }

        if (!noWay && (minCost > cost))
        {
            minCost = cost;
        }

    } while (next_permutation(numVec.begin(), numVec.end()));
    cout << minCost << endl;
    return 0;
}