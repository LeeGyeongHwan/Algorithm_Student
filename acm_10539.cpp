#include <iostream>
#include <vector>
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
    for (int i = 0; i < N; i++)
    {
        int num = intVec[i] * (i + 1);
        if (i == 0)
        {
            tmp = num;
            cout << tmp << " ";
            continue;
        }
        cout << num - tmp << " ";
        tmp = num;
    }

    return 0;
}