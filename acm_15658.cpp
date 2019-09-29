#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int maxNum = -1000000000;
int minNum = 1000000000;
vector<int> inputOP()
{
    vector<int> numvec;
    int n;
    for (int i = 1; i < 5; i++)
    {
        cin >> n;
        numvec.push_back(n);
    }
    return numvec;
}

void findMaxMin(int index, vector<int> numVec, int plus, int minus, int mul, int div, int num)
{
    if (index == N)
    {
        if (num > maxNum)
            maxNum = num;
        if (num < minNum)
            minNum = num;
        return;
    }

    if (plus > 0)
    {
        findMaxMin(index + 1, numVec, plus - 1, minus, mul, div, num + numVec[index]);
    }
    if (minus > 0)
    {
        findMaxMin(index + 1, numVec, plus, minus - 1, mul, div, num - numVec[index]);
    }
    if (mul > 0)
    {
        findMaxMin(index + 1, numVec, plus, minus, mul - 1, div, num * numVec[index]);
    }
    if (div > 0)
    {
        findMaxMin(index + 1, numVec, plus, minus, mul, div - 1, num / numVec[index]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> numVec, opVec;
    int tmp;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        numVec.push_back(tmp);
    }

    opVec = inputOP();

    findMaxMin(1, numVec, opVec[0], opVec[1], opVec[2], opVec[3], numVec[0]);

    cout << maxNum << "\n"
         << minNum << endl;

    return 0;
}