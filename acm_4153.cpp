#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    vector<int> numVec;
    do
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> num;
            numVec.push_back(num);
        }
        if (numVec.front() == 0)
            break;
        sort(numVec.begin(), numVec.end());
        int sum = numVec[0] * numVec[0] + numVec[1] * numVec[1];
        if (sum == numVec[2] * numVec[2])
            cout << "right"
                 << "\n";
        else
            cout << "wrong"
                 << "\n";
        numVec.clear();

    } while (1);
    return 0;
}