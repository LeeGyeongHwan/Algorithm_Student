#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    int tmp;
    vector<int> valueVec;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        valueVec.push_back(tmp);
    }
    int count = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int num = valueVec[i];
        count += K / num;
        K %= num;
        if (K == 0)
            break;
    }

    cout << count << endl;

    return 0;
}