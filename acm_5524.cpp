#include <iostream>

using namespace std;

int main()
{
    int N;
    string str;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] <= 90)
                cout << char(str[j] + 32);
            else
                cout << str[j];
        }
        cout << endl;
    }

    return 0;
}