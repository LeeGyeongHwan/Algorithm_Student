#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int day, a, b, c, d;

    cin >> day;
    cin >> a >> b >> c >> d;
    int num1 = (int)ceil((float)a / c);
    int num2 = (int)ceil((float)b / d);
    int max = num1 > num2 ? day - num1 : day - num2;
    cout << max << endl;

    return 0;
}