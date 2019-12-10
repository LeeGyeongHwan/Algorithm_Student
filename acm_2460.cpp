#include <iostream>

using namespace std;

int main()
{
    int outPeople, inPeople;
    int maxPeople = 0, totalPeople = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> outPeople >> inPeople;
        totalPeople = totalPeople - outPeople + inPeople;
        if (totalPeople > maxPeople)
            maxPeople = totalPeople;
    }

    cout << maxPeople << endl;
    return 0;
}