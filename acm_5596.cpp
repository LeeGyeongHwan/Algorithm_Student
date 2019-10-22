#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        sum1 += tmp;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        sum2 += tmp;
    }

    if (sum2 > sum1)
        cout << sum2 << endl;
    else
        cout << sum1 << endl;
}