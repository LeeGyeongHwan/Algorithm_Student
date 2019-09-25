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
        if (tmp == 0)
        {
            intVec.pop_back();
        }
        else
        {
            intVec.push_back(tmp);
        }
    }
    int sum = 0;
    for (int j = 0; j < intVec.size(); j++)
    {
        sum += intVec[j];
    }
    cout << sum << endl;

    return 0;
}