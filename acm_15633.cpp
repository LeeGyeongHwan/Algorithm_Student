#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;
    int sumN = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            sumN += i;
    }
    sumN = sumN * 5 - 24;

    cout << sumN << endl;

    return 0;
}