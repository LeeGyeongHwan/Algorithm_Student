#include <iostream>

using namespace std;

int main()
{
    long long S;

    cin >> S;
    long long num = 1;
    while (1)
    {
        S -= num;
        if (S < 0)
        {
            break;
        }
        num++;
    }
    cout << num - 1 << endl;

    return 0;
}