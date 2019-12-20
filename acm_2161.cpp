#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    vector<int> intVec;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        intVec.push_back(i);
    }
    while (intVec.size() != 1)
    {
        int num = intVec[1];
        cout << intVec[0] << " ";
        intVec.erase(intVec.begin(), intVec.begin() + 2);
        intVec.push_back(num);
    }
    cout << intVec[0] << endl;

    return 0;
}