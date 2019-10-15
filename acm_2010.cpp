#include <iostream>

using namespace std;

int main()
{
    int K, num;
    cin >> K;
    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        sum += num - 1;
    }
    sum++;
    cout << sum << endl;

    return 0;
}