#include <iostream>

using namespace std;

int main()
{

    string str;
    int sum = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            sum += 10;
            continue;
        }
        if (str[i] == str[i - 1])
            sum += 5;
        else
            sum += 10;
    }

    cout << sum << endl;
}