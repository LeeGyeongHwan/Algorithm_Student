#include <iostream>

using namespace std;

int main()
{
    int price, num, money;
    cin >> price >> num >> money;
    int sum = num * price - money;

    if (sum > 0)
        cout << sum << endl;
    else
        cout << 0 << endl;

    return 0;
}