#include <iostream>
using namespace std;

int findPeople(int floor, int room)
{
    if(floor==0)
        return room;
    int sumPeople =0;
    for (int i=1;i<=room;i++)
    {
        sumPeople += findPeople(floor-1,i);
    }
    return sumPeople;
}

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int floor, room;

        cin >> floor >> room;
        cout << findPeople(floor, room) << endl;
    }
}