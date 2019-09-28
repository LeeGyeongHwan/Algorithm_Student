#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputOP()
{
    vector<int> numvec;
    int n;
    for (int i = 1; i < 5; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            numvec.push_back(i);
        }
    }
    return numvec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, tmp;
    vector<int> intVec;
    vector<int> opVec;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }

    opVec = inputOP();
    int max = -1000000000;
    int min = 1000000000;
    do
    {
        int sum = intVec.front();
        for (int i = 0; i < num - 1; i++)
        {
            switch (opVec[i])
            {
            case 1:
                sum += intVec[i + 1];
                break;
            case 2:
                sum -= intVec[i + 1];
                break;
            case 3:
                sum *= intVec[i + 1];
                break;
            case 4:
                sum /= intVec[i + 1];
                break;
            }
        }
        if (sum > max)
            max = sum;
        if (sum < min)
            min = sum;
    } while (next_permutation(opVec.begin(), opVec.end()));
    cout << max << "\n"
         << min << endl;
    return 0;
}