#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, tmp;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());

    int wait = 0;
    for (int i = 0; i < N; i++)
    {
        wait += intVec[i] * (N - i);
    }
    cout << wait << endl;

    return 0;
}