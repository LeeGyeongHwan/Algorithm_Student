#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    vector<pair<int, int>> intV;
    vector<int> ordV;

    for (int i = 0; i < 8; i++)
    {
        cin >> num;
        intV.push_back(make_pair(num, i));
    }
    int sum = 0;
    sort(intV.begin(), intV.end());

    for (int i = 0; i < 5; i++)
    {
        sum += intV[7 - i].first;
        ordV.push_back(intV[7 - i].second);
    }
    sort(ordV.begin(), ordV.end());
    cout << sum << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ordV[i] + 1 << " ";
    }

    return 0;
}