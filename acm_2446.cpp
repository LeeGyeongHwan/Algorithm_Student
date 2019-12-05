#include <iostream>

using namespace std;

int main()
{
    int starNum;
    cin >> starNum;


    for (int a = 0; a < starNum; a++)
    {
        for (int j = 0; j < a; j++)
            cout << " ";
        for (int i = 0; i < starNum * 2 - (a * 2 + 1); i++)
            cout << "*";

        cout << endl;
    }

    for (int a = 1; a < starNum; a++)
    {
        for(int i=0;i<starNum-a-1;i++)
            cout<<" ";
        for(int i=0;i<(2*a+1);i++)
            cout<<"*";

        cout << endl;
    }


    return 0;
}