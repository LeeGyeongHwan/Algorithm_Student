#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, tmp;
    int V, countV = 0;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    cin >> V;
    for (int i = 0; i < N; i++)
    {
        if (intVec[i] == V)
            countV++;
    }
    cout << countV << endl;
    return 0;
}