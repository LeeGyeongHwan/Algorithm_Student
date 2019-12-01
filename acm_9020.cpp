#include <iostream>

using namespace std;

int main()
{
    int testCase, testNum;
    bool isPrime[10001] = {false};
    bool prime[10001] = {false};
    for (int i = 2; i <= 10000; i++)
    {
        if (isPrime[i] == false)
        {
            prime[i] = true;
            for (int j = i + i; j <= 10000; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> testNum;
        int tmp;
        for (int i = 2; i <= testNum / 2; i++)
        {
            if (prime[i] == true && prime[testNum - i] == true)
            {
                tmp = i;
            }
        }
        cout << tmp << " " << testNum - tmp << endl;
    }

    return 0;
}