#include <iostream>

using namespace std;

int main()
{
    int numTest, tmp;
    int additive = 1;
    int sum = 0;
    cin >> numTest;
    for (int i = 0; i < numTest; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            additive = 1;
        else
        {
            sum += additive;
            additive++;
        }
    }
    cout << sum << endl;

    return 0;
}