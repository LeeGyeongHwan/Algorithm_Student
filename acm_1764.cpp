#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    vector<string> hearsee, ansVec;
    string tmp;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++)
    {
        cin >> tmp;
        hearsee.push_back(tmp);
    }

    sort(hearsee.begin(), hearsee.end());
    for (int i = 1; i < N + M; i++)
    {
        if (hearsee[i - 1] == hearsee[i])
            ansVec.push_back(hearsee[i]);
    }

    cout << ansVec.size() << endl;
    for (int i = 0; i < ansVec.size(); i++)
    {
        cout << ansVec[i] << "\n";
    }

    return 0;
}