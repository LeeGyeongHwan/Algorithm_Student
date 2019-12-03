#include <iostream>

using namespace std;

int main()
{
    int starNum;
    cin >> starNum;
    for (int a = 0; a < starNum; a++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << " ";
        }
        for (int i = 0; i < starNum * 2 - (a*2+1); i++)
        {
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}