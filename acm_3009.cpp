#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int> > pVec;
    int a, b;
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b;
        pVec.push_back(make_pair(a, b));
    }
    int x = pVec[0].first ^ pVec[1].first ^ pVec[2].first;
    int y = pVec[0].second ^ pVec[1].second ^ pVec[2].second;
    cout << x << " " << y << endl;
    return 0;
}