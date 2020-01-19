#include <iostream>

using namespace std;

int main()
{
    string str;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 97 && str[i] <= 109) || (str[i] >= 65 && str[i] <= 77))
        {
            cout << char(str[i] + 13);
        }
        else if ((str[i] >= 108 && str[i] <= 122) || (str[i] >= 78 && str[i] <= 90))
        {
            cout << char(str[i] - 13);
        }
        else
        {
            cout << str[i];
        }
    }

    return 0;
}