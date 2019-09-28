#include <iostream>

using namespace std;

int main()
{
    int a, b, n, w;
    cin >> a >> b >> n >> w;
    int count = 0;
    int numofSheep;
    int numofGoat;
    for (int i = 1; i < n; i++)
    {
        int sum = a * i + b * (n - i);
        if (sum == w)
        {
            numofSheep = i;
            numofGoat = n - i;
            count++;
            if (count == 2)
                break;
        }
    }
    if (count == 1)
    {
        cout << numofSheep << " " << numofGoat << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}