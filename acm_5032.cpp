#include <iostream>

using namespace std;

int main()
{
    int empty, bottle, need;
    int sum = 0;
    cin >> empty >> bottle >> need;
    int total = empty + bottle;
    while (total / need)
    {
        sum += total / need;
        total = total / need + total % need;
    }
    cout << sum << endl;

    return 0;
}