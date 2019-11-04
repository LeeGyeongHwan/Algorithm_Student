#include <iostream>

using namespace std;

int main()
{
    string str;
    int len = 1;
    int max = 1;

    for (int i = 0; i < 3; i++)
    {
        cin >> str;
        for (int j = 1; j < str.length(); j++)
        {
            if (str[j] == str[j - 1])
            {
                len++;
                if (j == 7 && (len > max))
                {
                    max = len;
                }
            }
            else
            {
                if (len > max)
                {
                    max = len;
                }
                len = 1;
            }
        }
        cout << max << endl;
        len = 1;
        max = 1;
    }
    return 0;
}