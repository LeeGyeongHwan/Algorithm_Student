#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N;
    int num[10001] = {0};

    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        num[tmp]++;
    }
    for (int i = 0; i < 10001; i++)
    {
        if (num[i] != 0)
        {
            for (int j = 0; j < num[i]; j++)
                cout << i << "\n";
        }
    }

    return 0;
}