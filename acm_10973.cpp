#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, tmp;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    bool isAnswer = false;

    int i = N - 1;
    while (i > 0 && intVec[i - 1] <= intVec[i])
        i--;
    if (i <= 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    int j = N - 1;
    while (intVec[j] >= intVec[i - 1])
        j--;
    swap(intVec[i - 1], intVec[j]);
    j = N - 1;
    while (i < j)
    {
        swap(intVec[i], intVec[j]);
        i++;
        j--;
    }
    for (int i = 0; i < N; i++)
    {
        cout << intVec[i] << " ";
    }
    return 0;
}