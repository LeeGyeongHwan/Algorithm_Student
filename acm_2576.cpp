#include <iostream>

using namespace std;

int main()
{
    int tmp;
    int min = 100;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> tmp;
        if (tmp % 2 == 1)
        {
            count++;
            sum += tmp;
            if (min > tmp)
                min = tmp;
        }
    }
    if (count == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << sum << "\n"
             << min << endl;
    }

    return 0;
}