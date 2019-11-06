#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B;
    vector<int> intVec;
    cin >> A >> B;

    for (int i = 1; i <= A; i++)
    {
        if (A % i == 0)
        {
            intVec.push_back(i);
        }
    }
    if (intVec.size() >= (B - 1))
        cout << intVec[B - 1] << endl;
    else
        cout << "0" << endl;
    return 0;
}