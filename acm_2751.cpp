#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N;
    vector<int> numVec;
    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        numVec.push_back(tmp);
    }
    sort(numVec.begin(), numVec.end());
    for (int i = 0; i < N; i++)
    {
        cout << numVec[i] << "\n";
    }

    return 0;
}