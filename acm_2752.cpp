#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int tmp;
    vector<int> vec;
    for (int i = 0; i < 3; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < 3; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}