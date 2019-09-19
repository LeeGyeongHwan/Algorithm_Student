#include <iostream>
#include <vector>
using namespace std;

int GCD(int A, int B)
{
    if (B == 0)
    {
        return A;
    }
    else
    {
        return GCD(B, A % B);
    }
}

int main()
{
    int testCase;
    vector<vector<int>> intVec;
    vector<int> tmpVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            tmpVec.push_back(tmp);
        }
        intVec.push_back(tmpVec);
        tmpVec.clear();
    }

    for (int i = 0; i < testCase; i++)
    {
        long sum = 0; // int는 범위를 넘음
        vector<int> testVec = intVec[i];
        int length = testVec.size();
        for (int j = 0; j < length; j++)
        {
            for (int k = j + 1; k < length; k++)
            {
                int gcd = GCD(testVec[j],testVec[k]);
                sum = sum + gcd;
            }
        }
        cout << sum << endl;
    }
    return 0;
}