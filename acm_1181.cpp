#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> strVec;
    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        strVec.push_back(tmp);
    }

    sort(strVec.begin(), strVec.end());
    int count = 0;
    for (int i = 1; i <= 50; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (strVec[j].size() == i)
            {
                if(j>0 && (strVec[j]==strVec[j-1]))
                    continue;
                cout << strVec[j] << "\n";
                count++;
            }
        }
        if (count == N)
            break;
    }

    return 0;
}