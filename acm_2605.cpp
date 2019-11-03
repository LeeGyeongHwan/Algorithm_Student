#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, tmp;
    vector<int> numVec;
    vector<int>::iterator it;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        it = numVec.begin();
        int num = i - tmp;
        numVec.insert(it + num, i + 1);
    }

    for (int i = 0; i < N; i++)
    {
        cout << numVec[i] << " ";
    }

    return 0;
}