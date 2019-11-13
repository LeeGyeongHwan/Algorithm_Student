#include <iostream>

using namespace std;

void ad(int a, int b, int c)
{
    int benefit = b - c;

    if (a > benefit)
        cout << "do not advertise" << endl;
    else if (a == benefit)
        cout << "does not matter" << endl;
    else
        cout << "advertise" << endl;
}

int main()
{
    int T, a, b, c;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b >> c;
        ad(a, b, c);
    }

    return 0;
}