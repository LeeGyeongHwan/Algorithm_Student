#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, tmp;
    vector<int> a, b;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i] * b[N - i - 1];
    }
    cout << sum << endl;
    return 0;
}