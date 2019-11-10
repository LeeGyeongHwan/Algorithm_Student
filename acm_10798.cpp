#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int max = 0;
    vector<string> strVec;
    string tmp;
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        if (tmp.size() > max)
            max = tmp.size();
        strVec.push_back(tmp);
    }

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (strVec[j].size() <= i)
            {
                continue;
            }
            else
            {
                cout << strVec[j][i];
            }
        }
    }

    return 0;
}