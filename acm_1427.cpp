#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string num;
    cin >> num;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++)
    {
        cout << num[num.size() - 1 - i];
    }

    return 0;
}