#include <iostream>

using namespace std;

int GCD(int A, int B)
{
    if (B == 0)
    {
        return A;
    }
    else
    {
        return GCD(B, A % B);
    }
}

int main()
{
    int A, B;

    cin >> A >> B;

    int gcd = GCD(A, B);
    cout << gcd << endl;
    cout << A * B / gcd << endl;

    return 0;
}