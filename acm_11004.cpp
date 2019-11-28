#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, K, tmp;
    vector<int> intVec;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    cout << intVec[K - 1] << endl;

    return 0;
}