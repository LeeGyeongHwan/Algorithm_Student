#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string tmp;
    string str;
    unsigned int Num = 0;

    cin >> N;
    while (N)
    {
        cin >> str;
        if (str.size() <= 2)
        {
            N--;
            int num = atoi(str.c_str());
            if (tmp == "add")
            {
                Num |= 1 << (num - 1);
            }
            else if (tmp == "remove")
            {
                Num &= ~(1 << (num - 1));
            }
            else if (tmp == "check")
            {
                if (Num & 1 << (num - 1))
                    cout << "1\n";
                else
                    cout << "0\n";
            }
            else if (tmp == "toggle")
            {
                Num ^= 1 << (num - 1);
            }
        }
        else
        {
            if (str == "all")
            {
                Num |= 0xfffff;
                N--;
            }
            else if (str == "empty")
            {
                Num &= 0x000000;
                N--;
            }
            else
            {
                tmp = str;
            }
        }
    }
    return 0;
}