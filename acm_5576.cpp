#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int tmp;
    vector<int> uniW, uniK;
    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        uniW.push_back(tmp);
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        uniK.push_back(tmp);
    }
    sort(uniW.begin(), uniW.end());
    sort(uniK.begin(), uniK.end());

    int sum1 = uniW[7] + uniW[8] + uniW[9];
    int sum2 = uniK[7] + uniK[8] + uniK[9];

    cout << sum1 << " " << sum2 << endl;

    return 0;
}