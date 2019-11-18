#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, tmp;
    vector<int> intVec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    for (int i = 1; i <= intVec[0]; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (intVec[j] % i == 0)
                count++;
        }
        if (count == n)
            cout << i << endl;
    }

    return 0;
}