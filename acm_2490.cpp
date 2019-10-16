#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> tmp;
            if (tmp == 1)
                count++;
        }
        switch (count)
        {
        case 0:
            cout << 'D' << endl;
            break;
        case 1:
            cout << 'C' << endl;
            break;
        case 2:
            cout << 'B' << endl;
            break;
        case 3:
            cout << 'A' << endl;
            break;
        default:
            cout << 'E' << endl;
            break;
        }
        count = 0;
    }
    return 0;
}