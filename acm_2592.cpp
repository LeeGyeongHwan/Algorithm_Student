#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVec;
    int tmp;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        sum += tmp;
        intVec.push_back(tmp);
    }

    sort(intVec.begin(), intVec.end());

    int freq;
    int maxcount = 0;
    int count = 1;
    for (int i = 1; i < 10; i++)
    {
        if (intVec[i] == intVec[i - 1])
        {
            count++;
            if (i == 9)
            {
                if (maxcount < count)
                {
                    maxcount = count;
                    freq = i-1;
                }
            }
        }
        else
        {
            if (maxcount < count)
            {
                maxcount = count;
                freq = i-1;
            }
            count = 1;
        }
    }

    cout << sum / 10 << "\n"
         << intVec[freq] << endl;

    return 0;
}