#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N;
    vector<int> intVec;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        intVec.push_back(i);
    }

    do
    {
        for (int i = 0; i < N; i++)
        {
            cout << intVec[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(intVec.begin(), intVec.end()));

    return 0;
}