#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    const int limit = 123456 * 2 + 1;
    bool num[limit] = {false};
    bool prime[limit] = {false};

    for (int i = 2; i <= limit; i++)
    {
        if (num[i] == false)
        {
            prime[i] = true;
            for (int j = i + i; j <= limit; j += i)
            {
                num[j] = true;
            }
        }
    }

    do
    {
        int count = 0;
        cin >> N;
        if (N == 0)
            break;
        for (int k = N + 1; k <= (N + N); k++)
        {
            if (prime[k] == true)
            {
                count++;
            }
        }
        cout << count << endl;

    } while (1);

    return 0;
}