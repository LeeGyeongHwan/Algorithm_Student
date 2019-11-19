#include <iostream>

using namespace std;
int jcount = 0;
int icount = 0;

void startJOI(string str, int i)
{
    if (i + 2 < str.size())
    {
        if (str[i + 1] == 'O' && str[i + 2] == 'I')
            jcount++;
    }
}

void startIOI(string str, int i)
{
    if (i + 2 < str.size())
    {
        if (str[i + 1] == 'O' && str[i + 2] == 'I')
            icount++;
    }
}

int main()
{
    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'J')
        {
            startJOI(str, i);
        }
        if (str[i] == 'I')
        {
            startIOI(str, i);
        }
    }
    cout << jcount << "\n"
         << icount << endl;
    return 0;
}