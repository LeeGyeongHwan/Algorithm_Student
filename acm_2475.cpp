#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int tmp;
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        sum += pow(tmp, 2);
    }
    cout << sum % 10 << endl;

    return 0;
}