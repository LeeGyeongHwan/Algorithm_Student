#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;

    int A = 0;
    int B = 1;
    for (int i = 0; i < T; i++)
    {
        int tmp = A + B;
        A = B;
        B = tmp;
    }
    cout << A;
    return 0;
}