#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, tmp;
    cin >> N;
    vector<int> intVec;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }

    if (next_permutation(intVec.begin(), intVec.end()))
    {
        for (int i = 0; i < N; i++)
        {
            cout << intVec[i] << " ";
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}