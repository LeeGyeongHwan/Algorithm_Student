#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(tuple<string, int, int, int> A, tuple<string, int, int, int> B)
{
    if (get<1>(A) == get<1>(B))
    {
        if (get<2>(A) == get<2>(B))
        {
            if (get<3>(A) == get<3>(B))
            {
                return get<0>(A) < get<0>(B);
            }
            else
            {
                return get<3>(A) > get<3>(B);
            }
        }
        else
        {
            return get<2>(A) < get<2>(B);
        }
    }
    else
    {
        return get<1>(A) > get<1>(B);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, A, B, C;
    string tmp;
    vector<tuple<string, int, int, int>> tupleVec;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp >> A >> B >> C;
        tupleVec.push_back(make_tuple(tmp, A, B, C));
    }

    sort(tupleVec.begin(), tupleVec.end(), compare);
    for (int i = 0; i < N; i++)
    {
        cout << get<0>(tupleVec[i]) << "\n";
    }
    return 0;
}