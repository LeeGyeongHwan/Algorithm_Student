#include <iostream>

using namespace std;

int main()
{
    int M, N;
    int sum = 0;
    int min = 0;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        for (int j = 1; j <= (i + 1) / 2; j++)
        {
            if (j * j == i)
            {
                sum += i;
                if (min == 0)
                    min = i;
                break;
            }
        }
    }
    if (sum == 0)
        cout << "-1" << endl;
    else
    {
        cout << sum << "\n"
             << min << endl;
    }

    return 0;
}