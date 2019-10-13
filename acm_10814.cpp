#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<int, string, int> A, tuple<int, string, int> B)
{
    if (get<0>(A) == get<0>(B))
    {
        return get<2>(A) < get<2>(B);
    }
    else
    {
        return get<0>(A) < get<0>(B);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, tmp;
    string name;
    vector<tuple<int, string, int>> tupleVec;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp >> name;
        tupleVec.push_back(make_tuple(tmp, name, i));
    }

    sort(tupleVec.begin(), tupleVec.end(), compare);
    for (int i = 0; i < N; i++)
    {
        cout << get<0>(tupleVec[i]) << " " << get<1>(tupleVec[i]) << "\n";
    }
    return 0;
}