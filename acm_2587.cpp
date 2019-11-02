#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> intVec;
    int tmp;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        sum += tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());

    cout << sum / 5 << endl;
    cout << intVec[2] << endl;

    return 0;
}