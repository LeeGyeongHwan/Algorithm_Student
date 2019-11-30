#include <iostream>

using namespace std;

int main()
{
    string A, B, oper;
    cin >> A >> oper >> B;

    int numA = A.length() - 1;
    int numB = B.length() - 1;

    if (oper == "*")
    {
        cout << "1";
        for (int i = 0; i < numA + numB; i++)
            cout << "0";
    }
    else
    {

        int tmp;
        if (numA != numB)
        {
            if (numA > numB)
            {
                tmp = numA;
                numA = numB;
                numB = tmp;
            }
            cout << "1";
            for (int i = 0; i < numB; i++)
            {
                if (i == (numB - numA - 1))
                {
                    cout << "1";
                    continue;
                }
                cout << "0";
            }
        }
        else
        {
            cout << "2";
            for (int i = 0; i < numA; i++)
                cout << "0";
        }
    }

    return 0;
}