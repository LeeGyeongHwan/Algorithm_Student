#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    int monarr[] = {500, 100, 50, 10, 5, 1};
    int mon = 1000 - N;

    for (int i = 0; i < 6; i++)
    {
        int coin = mon / monarr[i];
        if (coin != 0)
        {
            count += coin;
            mon %= (coin * monarr[i]);
        }
    }
    cout << count << endl;

    return 0;
}