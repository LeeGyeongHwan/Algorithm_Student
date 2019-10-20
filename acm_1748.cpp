#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    int count = 0;
    int mul = 1;
    int ten = 10;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (i / ten == 0)
        {
            count += mul;
        }
        else
        {
            ten *= 10;
            mul++;
            count += mul;
        }
    }
    cout << count << endl;
}