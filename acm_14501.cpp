#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, maxCost = 0;
vector<pair<int, int>> pairVec;

void findMax(int day, int sum)
{
    if (day == N)
    {
        if (maxCost < sum)
            maxCost = sum;
        return;
    }
    if (day > N)
        return;

    findMax(day + pairVec[day].first, sum + pairVec[day].second);
    findMax(day + 1, sum);
}

int main()
{
    int t1, t2;
    pair<int, int> dayCost;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> t1 >> t2;
        dayCost.first = t1;
        dayCost.second = t2;
        pairVec.push_back(dayCost);
    }
    findMax(0, 0);
    cout << maxCost << endl;
    return 0;
}