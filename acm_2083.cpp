#include <iostream>

using namespace std;

int main()
{
    string name;
    int age, weight;

    while (1)
    {
        cin >> name >> age >> weight;
        if (!name.compare("#"))
            break;

        cout << name << " ";
        if (age > 17 || weight >= 80)
            cout << "Senior" << endl;
        else
            cout << "Junior" << endl;
    }
    return 0;
}