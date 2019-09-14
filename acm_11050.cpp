#include <iostream>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;
    int sum = 1;
    if (N - K > K)
    {
        for (int i = N - K + 1; i <= N; i++)
            sum *= i;
        for (int i = 1; i <= K; i++)
            sum /= i;
    }
    else
    {
        for (int i = K + 1; i <= N; i++)
            sum *= i;
        for (int i = 1; i <= N - K; i++)
            sum /= i;
    }
    cout << sum << endl;
}