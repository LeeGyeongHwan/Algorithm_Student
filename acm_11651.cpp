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
        tmpPair.first = y;
        tmpPair.second = x;
        pairVec.push_back(tmpPair);
    }
    sort(pairVec.begin(), pairVec.end());
    for (int i = 0; i < N; i++)
    {
        cout << pairVec[i].second << " " << pairVec[i].first << "\n";
    }

    return 0;
}