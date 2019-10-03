#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long f1 = 0;
    long long f2 = 1;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    cout << f1 << endl;

    return 0;
}