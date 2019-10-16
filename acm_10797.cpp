#include <iostream>

using namespace std;

int main()
{
    int num, tmp;

    cin >> num;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        if (num == tmp)
            sum++;
    }
    cout << sum << endl;
    return 0;
}