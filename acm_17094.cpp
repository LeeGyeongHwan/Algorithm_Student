#include <iostream>

using namespace std;

int main()
{
    int num;
    int sum2 = 0, sumE = 0;
    string str;

    cin >> num >> str;

    for (int i = 0; i < num; i++)
    {
        if (str[i] == '2')
            sum2++;
        else
            sumE++;
    }
    if (sum2 > sumE)
    {
        cout << 2 << endl;
    }
    else if (sum2 == sumE)
    {
        cout << "yee" << endl;
    }
    else
    {
        cout << "e" << endl;
    }

    return 0;
}