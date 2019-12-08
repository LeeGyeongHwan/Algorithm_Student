#include <iostream>

using namespace std;

int main()
{
    int num;
    int max = 0;
    int capi, capj;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> num;
            if (num > max)
            {
                max = num;
                capi = i;
                capj = j;
            }
        }
    }
    cout << max << "\n"
         << capi + 1 << " " << capj + 1;

    return 0;
}