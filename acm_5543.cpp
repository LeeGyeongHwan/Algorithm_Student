#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> hamVec;
    vector<int> driVec;
    int num;
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        hamVec.push_back(num);
    }
    for (int i = 0; i < 2; i++)
    {
        cin >> num;
        driVec.push_back(num);
    }
    sort(hamVec.begin(), hamVec.end());
    sort(driVec.begin(), driVec.end());

    cout << hamVec.front() + driVec.front() - 50 << endl;

    return 0;
}