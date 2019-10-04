#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test, tmp;
    vector<int> testVec;

    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> tmp;
        int j = 2;
        int count = 0;
        while (1)
        {
            if (tmp % j == 0)
            {
                count++;
                tmp /= j;
                if (tmp == 1)
                {
                    if (count == 0)
                        continue;
                    cout << j << " " << count << "\n";
                    count = 0;
                    break;
                }
            }
            else
            {
                if (count == 0)
                {
                    j++;
                    continue;
                }
                cout << j << " " << count << "\n";
                j++;
                count = 0;
            }
        }
    }

    return 0;
}