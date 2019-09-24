#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int height;
    vector<int> intVec;
    cin >> N;
    int maxHigh = 0;
    int high = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> height;
        intVec.push_back(height);
    }

    for (int i = 1; i < N; i++)
    {
        if (intVec[i] > intVec[i - 1])
        {
            high += intVec[i] - intVec[i - 1];
        }
        else
        {
            if (maxHigh < high)
            {
                maxHigh = high;
            }
            high = 0;
        }
    }
    if (high > maxHigh)
        maxHigh = high;
    cout << maxHigh << endl;
    return 0;
}