#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;

    int num;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                num = 1;
            }
            else
            {
                num = 0;
            }
        }
        else
        {
            num = 1;
        }
    }
    else
    {
        num = 0;
    }
    cout << num << endl;
    return 0;
}