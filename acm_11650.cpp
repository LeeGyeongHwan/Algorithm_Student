#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<pair<int, int>> pairVec;
    int x, y;
    cin >> N;
    pair<int, int> tmpPair;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        tmpPair.first = x;
        tmpPair.second = y;
        pairVec.push_back(tmpPair);
    }
    sort(pairVec.begin(), pairVec.end());
    for (int i = 0; i < N; i++)
    {
        cout << pairVec[i].first << " " << pairVec[i].second << "\n";
    }

    return 0;
}