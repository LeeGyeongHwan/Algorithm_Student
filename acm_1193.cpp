#include <iostream>

using namespace std;

int main()
{
    int num;

    cin >> num;

    int i;
    for (i = 1;; i++)
    {
        if (num - i <= 0)
            break;
        num -= i;
    }
    if (i % 2 == 0)
    {
        cout << num << "/" << i - num + 1 << endl;
    }
    else
    {
        cout << i - num + 1 << "/" << num << endl;
    }

    return 0;
}