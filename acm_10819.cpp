#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findSum(vector<int> intVec, int N)
{
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += abs(intVec[i] - intVec[i + 1]);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int N, tmp;
    cin >> N;
    vector<int> intVec;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }

    sort(intVec.begin(), intVec.end());

    int max = 0;
    do
    {
        int sum = findSum(intVec, N);
        if (sum > max)
            max = sum;
    } while (next_permutation(intVec.begin(), intVec.end()));
    cout << max << endl;
    return 0;
}