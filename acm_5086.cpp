#include <iostream>

using namespace std;

int main()
{
    const string factor = "factor";
    const string multiple = "multiple";
    const string neither = "neither";

    int a, b;

    cin >> a >> b;
    while (a != 0 && b != 0)
    {
        string str = neither;
        int result;
        if (a > b)
        {
            result = a % b;
            if (result == 0)
                str = multiple;
        }
        else
        {
            result = b % a;
            if (result == 0)
                str = factor;
        }
        cout<<str<<endl;
        cin >> a >> b;
    }
    return 0;
}
