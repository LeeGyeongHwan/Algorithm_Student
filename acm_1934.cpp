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
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        cout << A * B / GCD(A, B) << endl;
    }

    return 0;
}