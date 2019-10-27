#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> sci;
    int tmp, his, geo;

    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        sci.push_back(tmp);
    }
    cin >> his >> geo;
    sort(sci.begin(), sci.end());
    int sum = sci[1] + sci[2] + sci[3];
    if (his > geo)
        sum += his;
    else
        sum += geo;
    cout << sum << endl;

    return 0;
}