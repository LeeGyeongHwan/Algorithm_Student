#include <iostream>

using namespace std;

int main()
{
    string tmp;
    cin >> tmp;
    int count = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u')
            count++;
    }
    cout << count << endl;

    return 0;
}