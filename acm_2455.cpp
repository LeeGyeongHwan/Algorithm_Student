#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int out, in;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> out >> in;
        sum += in;
        sum -= out;
        if (max < sum)
            max = sum;
    }
    cout << max << endl;
}